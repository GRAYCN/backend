/*
 * engine.cpp
 *
 *  Created on: Jun 6, 2019
 *      Author: zqzuo
 */

#include <iostream>
#include "comp/cfg_compute.h"
#include "comp/art.h"

using namespace std;



//int main() {
//	CFG *cfg = new CFG_map();
//	GraphStore *graphstore = new NaiveGraphStore();
////	Partition *partition = nullptr;
////	cout << cfg << endl;
//
//	CFGCompute::load("/home/zqzuo/Desktop/inlined/final", "/home/zqzuo/Desktop/inlined/id_stmt_info.txt", "/home/zqzuo/Desktop/inlined/var_singleton_info.txt", cfg, graphstore);
//	CFGCompute::do_worklist(cfg, graphstore);
//
//	delete cfg;
//	delete graphstore;
//
////	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	return 0;
//}

// 对art存储进行robust测试
/*测试情况
 * */
int main(){
    Edge e1,e2,e3,e4,e5,e6;
    e1 = Edge(1, 2, 'a');
    e2 = Edge(3,7,'c');
    e3 = Edge(1,3,'a');
    e4 = Edge(1,4,'c');
    e5 = Edge(1,5,'b');
    e6 = Edge(2,3,'d');
    vector<Edge *> v1{&e1,&e3,&e5},v2{&e1,&e5,&e6},v3{&e1,&e3},v4{&e1,&e5},v5{&e2}, v6{&e1,&e4};
    vector<vector<Edge *> > vv = {v1,v2,v3,v4,v5};

    ART art = ART();
    art.edgeSort(vv);

    for (auto& it : vv){
        art.insert(it);
    }

    art.del()

    return 0;
}