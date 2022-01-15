#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src;
    int nbr;
    int wt;
    
    Edge(int src, int nbr, int wt){
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

int s_path_wt = INT_MAX;
int l_path_wt = INT_MIN;
int c_path_wt = INT_MAX;
int f_path_wt = INT_MIN;

string spath = "";
string lpath = "";
string cpath = "";
string fpath = "";

void multisolver(vector<vector<Edge*>> &graph, int src, int des, vector<bool> &visited, int criteria, int k, string psf, int wsf){
    if(src == des){
        if(wsf < s_path_wt){
            spath = psf;
            s_path_wt = wsf;
        }
        
        if(wsf > l_path_wt){
            lpath = psf;
            l_path_wt = wsf;
        }
        
        if(wsf > criteria && wsf < c_path_wt){
            c_path_wt = wsf;
            cpath = psf;
        }
        
        if(wsf < criteria && wsf > f_path_wt){
            f_path_wt = wsf;
            fpath = psf;
        }
        return;
    }
    
    visited[src] = true;
    
    for(Edge* edge : graph[src]){
        int nei = edge->nbr;
        
        if(!visited[nei]){
            multisolver(graph, nei, des, visited, criteria, k, psf + to_string(nei), wsf + edge->wt);
        }
    }
    
    visited[src] = false;
}

void kthLargest(vector<vector<Edge*>> &graph, int src, int des, vector<bool> visited, int k){
    int val = INT_MAX;

    for(int i = 0; i < k; i++){
        fpath = "";
        f_path_wt = INT_MIN;

        multisolver(graph, src, des, visited, val, k, to_string(src) + fpath, 0);
        val = f_path_wt;
    }

    string kth_largest_path = fpath;
    cout << k << "th largest path = " << kth_largest_path << "@" << val << endl;
}

int main() {
	int v, e;
	cin >> v >> e;
	
	vector<vector<Edge*>> graph(v, vector<Edge*>());
	for(int i = 0; i < e; i++){
	    int v1, v2, wt;
	    cin >> v1 >> v2 >> wt;
	    
	    Edge* e1 = new Edge(v1, v2, wt);
	    Edge* e2 = new Edge(v1, v2, wt);
	    
	    graph[v1].push_back(e1);
	    graph[v2].push_back(e2);
	}
	
	int src, des, criteria, k;
	cin >> src >> des >> criteria >> k;
	vector<bool> visited(v, false);
	
	string s = "";
	multisolver(graph, src, des, visited, criteria, k, s + to_string(src), 0);
	
	cout << "Smallest Path = " << spath << "@" << s_path_wt << endl;
	cout << "Largest Path = " << lpath << "@" << l_path_wt << endl;
	cout << "Just Larger Path than " << criteria << " = " << cpath << "@" << c_path_wt << endl;
	cout << "Just Smaller Path than " << criteria << " = " << fpath << "@" << f_path_wt << endl;
    kthLargest(graph, src, des, visited, k);
	return 0;
}
