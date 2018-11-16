#include "pgridindex.h"


PGrid::PGrid(P_ID_INT id, const PointXY& max, const PointXY& min):
    _grid_id(id),
    _max(max),
    _min(min){
    //初始化_block_ids
}

PGrid::~PGrid(void){
}

bool PGrid::addPoint(const PointXYZ& point){
    if (_temp_num >=  _flush_num){
        P_ID_INT block_id = flush();
        if (block_id >= 0){
            _block_ids.push_back(block_id);
        }
    }
    //
    _temp.push_back(point);
    ++_temp_num;
    ++_num;        
}

P_ID_INT PGrid::flush(){
    //数据落盘，
    //******?????
    //清空temp中数据
    _temp.clear();
    _temp_num = 0;
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
GridIndex::GridIndex(const std::string& file_path):
    _index_path(file_path){
}

GridIndex::~GridIndex(void){
}

bool GridIndex::load(){
}



