% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/time-series.r
\name{getTsGeometry}
\alias{getTsGeometry}
\title{Gets the time series geometry of an xts, to be passed to a C API}
\usage{
getTsGeometry(xtseries)
}
\arguments{
\item{xtseries}{the uni- or multi-variate xts time series}
}
\value{
an S4 object of class 'RegularTimeSeriesGeometry'
}
\description{
Gets the time series geometry of an xts, to be passed to a C API
}
