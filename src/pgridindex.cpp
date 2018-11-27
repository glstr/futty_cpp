#include "pgridindex.h"

PointCloud::PointCloud(void):_pcloud(){
}

PointCloud::~PointCloud(void){
}

bool PointCloud::load(const std::string& file_path){
    return true;
}


///////////////////////////////////////////////////////////////////////////////////////////////////
PGrid::PGrid(P_ID_INT id, const PointXY& max, const PointXY& min, 
        P_SIZE_INT flush_num, PDataStore* data_store):
    _grid_id(id),
    _max(max),
    _min(min),
    _num(0),
    _temp_num(0),
    _flush_num(flush_num),
    _temp(),
    _data_store(data_store){
    //初始化_block_ids
}

PGrid::~PGrid(void){
}

bool PGrid::addPoint(const PointXYZ& point){
    //超过阈值，将点云落盘
    if (_temp_num >=  _flush_num){
        flush();
    }
    //
    _temp.push_back(point);
    ++_temp_num;
    ++_num;        
}

P_ID_INT PGrid::flush(){
    //数据落盘，
    _data_store->add(_grid_id, _temp); 
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


