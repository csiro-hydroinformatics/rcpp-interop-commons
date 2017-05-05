#pragma once

// Template specialisations for interop with Rcpp

#include <Rcpp.h>

#include "cinterop/timeseries_c_interop.h"
#include "cinterop/object_lifetimes.hpp"

using namespace Rcpp;

namespace cinterop
{
	namespace timeseries
	{

		template<typename From>
		void to_regular_time_series_geometry(const From& rTsInfo, regular_time_series_geometry& mts);

		template<typename To>
		To from_regular_time_series_geometry(const regular_time_series_geometry& mts);

		template<typename From>
		regular_time_series_geometry to_regular_time_series_geometry(const From& rTsInfo)
		{
			regular_time_series_geometry mts;
			to_regular_time_series_geometry(rTsInfo, mts);
			return mts;
		}

		template<typename From>
		regular_time_series_geometry* to_regular_time_series_geometry_ptr(const From& rTsInfo)
		{
			regular_time_series_geometry* mts = new regular_time_series_geometry();
			to_regular_time_series_geometry(rTsInfo, *mts);
			return mts;
		}

		template<typename From>
		multi_regular_time_series_data to_multi_regular_time_series_data(const From& timeSeriesEnsemble);

		template<typename To>
		To from_multi_regular_time_series_data(const multi_regular_time_series_data& mts);



	}

	namespace disposal {
		template<>
		inline void dispose_of<multi_regular_time_series_data>(multi_regular_time_series_data& d)
		{
			if (d.numeric_data != nullptr)
			{
				for (int i = 0; i < d.ensemble_size; i++)
					if (d.numeric_data[i] != nullptr)
					{
						delete d.numeric_data[i];
						d.numeric_data[i] = nullptr;
					}
				d.numeric_data = nullptr;
			}
		}
	}

}