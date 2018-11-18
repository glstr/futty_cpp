#include "pgridindex.h"

PointCloud::PointCloud(void){
}

PointCloud::~PointCloud(void){
}

bool PointCloud::load(const std::string& file_path){
    return true;
}


///////////////////////////////////////////////////////////////////////////////////////////////////
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

void GridIndex::addPointCloud(const std::string& file_path, FILE_MODE mode){
    //file -> pointcloud
    PointCloud* cloud = new PointCloud();
    bool ok = cloud->load(file_path);
    if (!ok) {
        return;
    }
    //pointcloud -> pgrid
}

///////////////////////////////////////////////////////////////////////////////////////////////////
PDataStore::PDataStore(void){
}

PDataStore::~PDataStore(void){
}

void PDataStore::load(const std::string& file_path, const std::string& data_path){
}

bool PDataStore::add(P_ID_INT grid_id, const std::vector<PointXYZ>& pcloud){
    return true;
}

void PDataStore::get(P_ID_INT grid_id, std::vector<PointXYZ>& pcloud){
}

bool PDataStore::del(P_ID_INT grid_id){
}

bool PDataStore::update(P_ID_INT, const std::vector<PointXYZ>& pcloud){
}

bool PDataStore::write(){
}


