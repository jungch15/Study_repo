#ifndef WGRAPHDIJKSTRA_H_
#define WGRAPHDIJKSTRA_H_

#include "WGraph.h"

class WGraphDijkstra: public WGraph{
private:
	int dist[MAX_SIZE];//시작노드로부터 최단 경로 거리 만약 시작노드와 간선이 없으면 INF로 값이 넣어진다.
	bool found[MAX_SIZE];// 정점을 방문했는지 안했는지 표시하기 위한 배열
public:
	int chooseVertex(){//prim의 알고리즘에서 가장 가중치가 적은 간선을 가진 정점을 반한하는 함수와 동일하다.
		int minv =0;
		int mindist = INF;//최대값으로 설정해줘야 가장 작은 값을 추출할 수 있다.
		for(int i=0;i<size;i++)
			if(!found[i] && mindist > dist[i]){
				mindist = dist[i];
				minv = i;
			}
		return minv;
	}
	void ShortestPath(int start){ //prim의 최소비용 신장트리(MST)와 상당히 유사하다. 거의 같다고 보면 된다.
		for(int i=0;i<size;i++){ //초기화
			dist[i] = INF;
			found[i] = false;
		}
		dist[start] =0;
		found[start] = true;
		for(int i=0;i<size;i++){
			printf("Step%2d:",i+1);
			printDistance();
			int u = chooseVertex(); //거리가 가장 작은 정점 반환
			found[u] = true;
			for(int v=0;v<size;v++){//dist 갱신
				if(!found[v] && getEdge(u,v) + dist[u] < dist[v])//dist[u]는 u까지 최단거리이므로 u,v의 간선과 이를 더한것이 dist[v]보다 작으면 실행한다.
					dist[v] = getEdge(u,v) + dist[u];
			}

		}
	}
	void printDistance(){
		for(int i=0;i<size;i++)
			printf("%5d",dist[i]);
		printf("\n");
	}
};


#endif /* WGRAPHDIJKSTRA_H_ */
