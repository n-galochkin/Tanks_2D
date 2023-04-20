#include "PerformanceMeasurer.h"

#include <chrono>
#include <string>

#include "Logger.h"

void PerformanceMeasurer::start_measuring(const string& metric_name)
{
	if (metrics_.contains(metric_name) == false)
	{
		metrics_[metric_name] = PerformanceMetric();
	}

	metrics_[metric_name].start_time = steady_clock::now();
}

void PerformanceMeasurer::end_measuring(const string& metric_name)
{
	if (metrics_.contains(metric_name) == false)
	{
		// TODO: throw exception
		return;
	}

	const auto end_time = steady_clock::now();
	const duration<float> elapsed_time = end_time - metrics_[metric_name].start_time;

	if (elapsed_time > metrics_[metric_name].max_time)
	{
		metrics_[metric_name].max_time = elapsed_time;

		Logger::log(Warning, format("{0} time: {1:.5f}s", metric_name, elapsed_time.count()));
	}
}
