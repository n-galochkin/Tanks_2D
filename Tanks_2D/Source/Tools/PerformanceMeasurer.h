#pragma once
#include <chrono>
#include <map>
#include <xstring>

using namespace std;
using namespace chrono;

struct PerformanceMetric
{
    string name;
    
    time_point<steady_clock> start_time;
    time_point<steady_clock> end_time;

    duration<float> elapsed_time;
    duration<float> max_time;
};

class PerformanceMeasurer
{
public:

    void start_measuring(const std::string& metric_name);

    void end_measuring(const std::string& metric_name);

private:
    void add_metric(std::string metric_name);

private:
    map<string, PerformanceMetric> Metrics;
};
