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


class PGrid{
public:
    PGrid(P_ID_INT id, const PointXY& max, const PointXY& min);
    virtual ~PGrid(void);

    bool addPoint(const PointXYZ& point);
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
    std::vector<P_ID_INT> _block_ids;
    std::vector<PointXYZ> _temp;
};


class GridIndex{
public:
    GridIndex(const std::string& file_path);
    virtual ~GridIndex(void);

    bool load();
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



