#include<iostream>
using namespace std;

 
class Server {
public:
    string sid, host;
    int weight;
    bool isHealthy = true;
    int activeConnections = 0;
 
    Server(string id, string h, int w = 1) : sid(id), host(h), weight(w) {}
 
    string handle(const string& req) {
        activeConnections++;
        // ... actually serve ...
        return "Response from " + sid;
    }
};
 
class LoadBalancingStrategy {
public:
    virtual Server* choose(vector<Server*>& servers) = 0;
    virtual ~LoadBalancingStrategy() = default;
};
 
class RoundRobin : public LoadBalancingStrategy {
    int idx = 0;
    mutex mtx;
public:
    Server* choose(vector<Server*>& servers) override {
        vector<Server*> healthy;
        for (auto* s : servers) if (s->isHealthy) healthy.push_back(s);
        if (healthy.empty()) return nullptr;
        lock_guard<mutex> lock(mtx);
        return healthy[idx++ % healthy.size()];
    }
};
 
class LeastConnections : public LoadBalancingStrategy {
public:
    Server* choose(vector<Server*>& servers) override {
        Server* best = nullptr;
        for (auto* s : servers) {
            if (!s->isHealthy) continue;
            if (!best || s->activeConnections < best->activeConnections) best = s;
        }
        return best;
    }
};

 
class LoadBalancer {
    vector<Server*> servers;
    LoadBalancingStrategy* strategy;
public:
    LoadBalancer(vector<Server*> s, LoadBalancingStrategy* st)
        : servers(move(s)), strategy(st) {}
 
    void addServer(Server* s) { servers.push_back(s); }
    void removeServer(const string& sid) {
        servers.erase(remove_if(servers.begin(), servers.end(),
            [&](Server* s){ return s->sid == sid; }), servers.end());
    }
 
    string route(const string& req) {
        Server* s = strategy->choose(servers);
        if (!s) return "";
        string resp = s->handle(req);
        s->activeConnections--;
        return resp;
    }
};

int main() {
    srand(time(nullptr));

    Server s1("web-1", "10.0.0.1:8080", 1);
    Server s2("web-2", "10.0.0.2:8080", 2);
    Server s3("web-3", "10.0.0.3:8080", 3);

    vector<Server*> servers = {&s1, &s2, &s3};

    // --- Round Robin ---
    RoundRobin rr;
    LoadBalancer lb1(servers, &rr);
    cout << "=== Round Robin ===\n";
    for (int i = 0; i < 6; i++)
        cout << lb1.route("req-" + to_string(i)) << "\n";

    // --- Least Connections ---
    s1.activeConnections = 5;
    s2.activeConnections = 1;
    s3.activeConnections = 3;

    LeastConnections lc;
    LoadBalancer lb2(servers, &lc);
    cout << "\n=== Least Connections ===\n";
    for (int i = 0; i < 4; i++)
        cout << lb2.route("req-" + to_string(i)) << "\n";


    return 0;
}