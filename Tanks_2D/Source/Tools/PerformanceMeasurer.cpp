#include "PerformanceMeasurer.h"

#include <chrono>
#include <iostream>
#include <string>

void PerformanceMeasurer::start_measuring(const string& metric_name)
{
    if (Metrics.contains(metric_name) == false)
    {
        Metrics[metric_name] = PerformanceMetric();
    }

    Metrics[metric_name].start_time = steady_clock::now();
}

void PerformanceMeasurer::end_measuring(const string& metric_name)
{
    if (Metrics.contains(metric_name) == false)
    {
        // TODO: throw exception
        return;
    }

    const auto end_time = steady_clock::now();
    const duration<float> elapsed_time = end_time - Metrics[metric_name].start_time;

    if(elapsed_time > Metrics[metric_name].max_time)
    {
        Metrics[metric_name].max_time = elapsed_time;
        
        std::cout << metric_name + " time: " << elapsed_time.count() << "s" << std::endl;
    }
}
