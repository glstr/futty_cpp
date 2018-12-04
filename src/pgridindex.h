#pragma once
#include <map>
#include <string>
#include <vector>

#define P_SIZE_INT int
#define P_ID_INT int

struct PointXY{
    double x;
    double y;
};

struct PointXYZ{
    double x;
    double y;
    double z;
    long r;
    long g;
    long b;
    long roll;
    long pitch;
    long yaw;
    long time;
};

enum FILE_MODE{
        XYZ = 0,
        BLS = 1,
        LAS = 2,
    };

class PointCloud{
public:
    PointCloud(void);
    virtual ~PointCloud(void);

    bool load(const std::string& file_path);
    
private:
    std::vector<PointXYZ> _pcloud;
};

class PDataStore;
class PGrid{
public:
    PGrid(P_ID_INT id, const PointXY& max, const PointXY& min, 
            P_SIZE_INT flush_num, PDataStore* data_store);
    virtual ~PGrid(void);

    bool addPoint(const PointXYZ& point);

    P_SIZE_INT getFlushNum(){
        return _flush_num;
    }
    void setFlushNum(P_SIZE_INT flush_num){
        _flush_num = flush_num;
    }
private:
    P_ID_INT flush();
private:
    P_ID_INT _grid_id;
    //区域范围
    PointXY _max; 
    PointXY _min;
    P_SIZE_INT _num;
    P_SIZE_INT _temp_num;
    P_SIZE_INT _flush_num;
    std::vector<PointXYZ> _temp;
    PDataStore *_data_store;
};


class GridIndex{
public:
    GridIndex(const std::string& file_path);
    virtual ~GridIndex(void);

    
    bool load();
    void addPointCloud(const std::string& file_path, FILE_MODE mode=BLS);

    void setRegion(const PointXY& max, const PointXY& min);
    void getRegion();

    void setRegionSize(P_SIZE_INT m, P_SIZE_INT n);
    void getRegionSize();

    void setPrecision(double precision);
    double getPrecision();
private:
    void getGridId();
private:
    //区域范围
    PointXY _max;
    PointXY _min;
    //区域网格数
    P_SIZE_INT _m;
    P_SIZE_INT _n;
    //点云精度
    double _precision;
    //索引文件
    std::string _index_path;
    //数据文件
    std::string _data_path;
    //网格数据
    std::vector<PGrid> _grids;
};

//数据落盘
//维护grid_id到block_id的映射关系
//数据文件的组织方式,block_id对应数据的信息
class PDataStore{
public:
    PDataStore(const std::string& file_path, P_SIZE_INT block_size);
    virtual ~PDataStore(void);

    struct BlockInfo {
        explicit BlockInfo() : size(0), capacity(0), enable(false) {}
        bool enable;
        P_SIZE_INT size;
        P_SIZE_INT capacity; 
    };
    void load(const std::string& file_path, const std::string& data_path);

    bool add(P_ID_INT grid_id, const std::vector<PointXYZ>& pcloud);
    void get(P_ID_INT grid_id, std::vector<PointXYZ>& pcloud);
    bool del(P_ID_INT grid_id);
    bool update(P_ID_INT grid_id, const std::vector<PointXYZ>& pcloud);
private:
    bool write();
private:
    std::string _file_path;
    P_SIZE_INT _blocks_num;
    P_SIZE_INT _block_size;
    std::map< P_ID_INT, std::vector<P_ID_INT> > _grid_to_block;
    std::vector<BlockInfo> _blocks_info;

    FILE* _f;
};



