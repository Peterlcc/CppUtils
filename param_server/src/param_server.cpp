#include"ros/ros.h"
#include<iostream>
#include<string>
#include"jsoncpp/json/json.h"
#include"param_server/BridgeInfo.h"
#include"param_server/Messsage.h"

using namespace std;
using namespace Json;

ros::NodeHandle *nh=nullptr;

bool serviceCall(param_server::MesssageRequest &request,param_server::MesssageResponse &response)
{
    string json=request.request;
    BridgeInfo info(json);
    ROS_INFO("get json :%s",json.c_str());

    int val0;
    bool val1;
    unsigned int val2;
    double val3;
    string val4;
    
    bool flag=true;
    Value result;
    result["operator"]=info.getOp();
    
    if(info.getOp()==0){
         
        switch (info.getType())
        {
            case 0:
                ros::param::get(info.getName(),val0);
                ROS_INFO("get value:%d",val0);
                
                result["response"]=val0;
                break;
            case 1:
                ros::param::get(info.getName(),val1);
                ROS_INFO("get value:%d",val1);

                result["response"]=val1;
                break;
            case 2:
                ROS_INFO("get value:%d",val2);

                result["response"]=val2;
                break;
            case 3:
                ros::param::get(info.getName(),val3);
                ROS_INFO("get value:%f",val3);

                result["response"]=val3;
                break;
            case 4:
                ros::param::get(info.getName(),val4);
                ROS_INFO("get value:%s",val4.c_str());

                result["response"]=val4;
                break;
            default:
                flag=false;
                break;
        }
    }else{
       
        info.getValue(val0, val1, val2, val3, val4);
        result["response"]="succeed";
        switch (info.getType())
        {
            case 0:
                ROS_INFO("set value:%d",val0);
                ros::param::set(info.getName(),val0);
                break;
            case 1:
                ROS_INFO("set value:%d",val1);
                ros::param::set(info.getName(),val1);
                break;
            case 2:
                ROS_INFO("set value:%d",val2);
                break;
            case 3:
                ROS_INFO("set value:%f",val3);
                ros::param::set(info.getName(),val3);
                break;
            case 4:
                ROS_INFO("set value:%s",val4.c_str());
                ros::param::set(info.getName(),val4);
                break;
            default:
                flag=false;
                result["response"]="failed";
                break;
        }
    }
    if(flag){
        result["code"]=200;
    }else{
        result["code"]=400;
    }
    response.response=result.toStyledString();
    return flag;
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "param_server");
    nh=new ros::NodeHandle();
    ros::ServiceServer server=nh->advertiseService("/param_operation",serviceCall);
    ROS_INFO("param server is ready now!");
    ros::spin();
    delete nh;
    return 0;
}