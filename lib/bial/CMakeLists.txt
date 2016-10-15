cmake_minimum_required(VERSION 2.8.5)

# set(CMAKE_C_COMPILER "/opt/intel/bin/icc")
# set(CMAKE_CXX_COMPILER "/opt/intel/bin/icpc")
# set(CMAKE_BUILD_TYPE Release)

add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DREAL_FLOAT") #  -diag-disable 576

include_directories(inc src)

aux_source_directory(src SOURCE_FILES)

add_definitions(-DBIAL_EXPLICIT_LIB)

set (BIAL_CPPs Adjacency AdjacencyGrayCode AdjacencyIterator AdjacencyMarchingCube AdjacencyRound BSpline BinaryCOG BinaryComplement Bit BrainCOG BrainInhomogeneity BrainIntensities BrainSkullStripping BrainTissueSegmentation BucketQueue ChessBoardDistanceFunction CityBlockDistanceFunction ClusteringIFT Color ColorChannel ColorFeature ColorHSI ColorLab ColorMedianFeature ColorRGB Common ConnPathFunction Correlation DFIDE DegeneratedIFT DicomHeader DiffPathFunction DiffusionFunction Display DrawBox DrawCircle DrawIntersection DrawLine DrawPoint DrawSVGGraph DrawSequence DrawShape EdgeLazyWalk EdgeLiveWire EdgeMaxPathFunction EdgeRiverBed EuclideanDistanceFunction Feature FeaturePathFunction FeatureResize File FileFeature FileSignal FilteringAnisotropicDiffusion FilteringGaussian FilteringMean FilteringMedian FilteringOptimalAnisotropicDiffusion FuzzyCMeans GeoSumPathFunction GeodesicPathFunction Geometrics GeometricsAffine GeometricsRotate GeometricsScale GeometricsShear GeometricsTranslate GradientCanny GradientDirectional GradientGabor GradientMorphological GradientPosOperations GradientScaleCanny GradientSobel Graph HeartCOG HeartSegmentation HierarchicalGraph HierarchicalPathFunction Histogram HoughCircle Image ImageEquals ImageFrame ImageIFT ImageInterpolation ImageMerge ImageROI ImageResize ImageSplit ImageSwapDims InfBucketQueue Integral IntensityGlobals IntensityLocals Kernel KernelBox KernelGabor KernelGaussian KernelIterator KernelRound KernelSobel KnnGraphAdjacency LSHGraphAdjacency LocalMaxPathFunction MatrixDeterminant MatrixIdentity MatrixInverse MatrixPolar MatrixResize MatrixTranspose MaxPathFunction MaxSumPathFunction MedianFeature MinPathFunction MinimumSpanningTree MorphologyDilation MorphologyErosion MultiImage NiftiHeader OPFClusterMatching OPFHierarchicalClustering OPFSpatialClustering OPFSpectralClustering OrientedExternPathFunction OrientedInternPathFunction PNMHeader PathFunction PixelInterpolation Plotting PreEuclideanDistanceFunction RandomQueue RealColor Sample SampleRandom SampleUniform SegmentationBackground SegmentationBorder SegmentationConnectedComponents SegmentationGeoStar SegmentationHysteresis SegmentationIntensityThreshold SegmentationMST SegmentationOctants SegmentationOtsuThreshold SegmentationQuadrants SegmentationSurface SegmentationWatershed Signal SignalAccumulate SignalEmptyBins SignalEqualize SignalHysteresis SignalKeyPoints SignalMedianFilter SignalNormalize SignalOtsuThreshold SortingBinarySearch SortingSort SpatialFeature SquareEuclideanDistanceFunction StatisticsAverage StatisticsBaddeley StatisticsDice StatisticsJaccard StatisticsKappa StatisticsMAD StatisticsObsAgree StatisticsPosNeg StatisticsStdDev SumPathFunction Table TransformEuclDist TransformEuclDistInv)

foreach(BIAL_CPP ${BIAL_CPPs})
  add_definitions(-DBIAL_${BIAL_CPP})
endforeach()

include_directories(../lsh/inc)
# include_directories(../SLIC/inc)

# add_library(bial SHARED ${SOURCE_FILES}) # queremos desabilitar alguns arquivos seletivamente
add_library(bial
  # src/Adjacency.cpp
  # src/AdjacencyGrayCode.cpp
  # src/AdjacencyIterator.cpp
  # src/AdjacencyMarchingCube.cpp
  # src/AdjacencyRound.cpp
  # src/BSpline.cpp
  # src/BinaryCOG.cpp
  # src/BinaryComplement.cpp
  # src/Bit.cpp
  # # src/Brain.cpp --> Brain.hpp is missing
  # src/BrainCOG.cpp
  # src/BrainInhomogeneity.cpp
  # src/BrainIntensities.cpp
  # src/BrainSkullStripping.cpp
  # src/BrainTissueSegmentation.cpp
  # src/BucketQueue.cpp
  # src/ChessBoardDistanceFunction.cpp
  # src/CityBlockDistanceFunction.cpp
  # src/ClusteringIFT.cpp
  # src/Color.cpp
  # src/ColorChannel.cpp
  # src/ColorFeature.cpp
  # src/ColorHSI.cpp
  # src/ColorLab.cpp
  # src/ColorMedianFeature.cpp
  # src/ColorRGB.cpp
  src/Common.cpp
  # src/ConnPathFunction.cpp
  # src/Correlation.cpp
  # src/DFIDE.cpp
  # src/DegeneratedIFT.cpp
  # src/DicomHeader.cpp
  # src/DiffPathFunction.cpp
  # src/DiffusionFunction.cpp
  # src/Display.cpp
  # src/DrawBox.cpp
  # src/DrawCircle.cpp
  # src/DrawIntersection.cpp
  # src/DrawLine.cpp
  # src/DrawPoint.cpp
  # src/DrawSVGGraph.cpp
  # src/DrawSequence.cpp
  # src/DrawShape.cpp
  # src/EdgeLazyWalk.cpp
  # src/EdgeLiveWire.cpp
  # src/EdgeMaxPathFunction.cpp
  # src/EdgeRiverBed.cpp
  # src/EuclideanDistanceFunction.cpp
  # src/Feature.cpp
  # src/FeaturePathFunction.cpp
  # src/FeatureResize.cpp
  # src/File.cpp
  # src/FileFeature.cpp
  # src/FileSignal.cpp
  # src/FilteringAnisotropicDiffusion.cpp
  # src/FilteringGaussian.cpp
  # src/FilteringMean.cpp
  # src/FilteringMedian.cpp
  # src/FilteringOptimalAnisotropicDiffusion.cpp
  # src/FuzzyCMeans.cpp
  # src/GeoSumPathFunction.cpp
  # src/GeodesicPathFunction.cpp
  # src/Geometrics.cpp
  # src/GeometricsAffine.cpp
  # src/GeometricsRotate.cpp
  # src/GeometricsScale.cpp
  # src/GeometricsShear.cpp
  # src/GeometricsTranslate.cpp
  # src/GradientCanny.cpp
  # src/GradientDirectional.cpp
  # src/GradientGabor.cpp
  # src/GradientMorphological.cpp
  # src/GradientPosOperations.cpp
  # src/GradientScaleCanny.cpp
  # src/GradientSobel.cpp
  # src/Graph.cpp
  # src/HeartCOG.cpp
  # src/HeartSegmentation.cpp
  # src/HierarchicalGraph.cpp
  # src/HierarchicalPathFunction.cpp
  # src/Histogram.cpp
  # src/HoughCircle.cpp
  # src/Image.cpp
  # src/ImageEquals.cpp
  # src/ImageFrame.cpp
  # src/ImageIFT.cpp
  # src/ImageInterpolation.cpp
  # src/ImageMerge.cpp
  # src/ImageROI.cpp
  # src/ImageResize.cpp
  # src/ImageSplit.cpp
  # src/ImageSwapDims.cpp
  # src/InfBucketQueue.cpp
  # src/Integral.cpp
  # src/IntensityGlobals.cpp
  # src/IntensityLocals.cpp
  # src/Kernel.cpp
  # src/KernelBox.cpp
  # src/KernelGabor.cpp
  # src/KernelGaussian.cpp
  # src/KernelIterator.cpp
  # src/KernelRound.cpp
  # src/KernelSobel.cpp
  # src/KnnGraphAdjacency.cpp
  # src/LSHGraphAdjacency.cpp
  # src/LocalMaxPathFunction.cpp
  # # src/MarchingCubes.cpp
  # src/MatrixDeterminant.cpp
  # src/MatrixIdentity.cpp
  # src/MatrixInverse.cpp
  # src/MatrixPolar.cpp
  # src/MatrixResize.cpp
  # src/MatrixTranspose.cpp
  # src/MaxPathFunction.cpp
  # src/MaxSumPathFunction.cpp
  # src/MedianFeature.cpp
  # src/MinPathFunction.cpp
  # src/MinimumSpanningTree.cpp
  # src/MorphologyDilation.cpp
  # src/MorphologyErosion.cpp
  # src/MultiImage.cpp
  # src/NiftiHeader.cpp
  # src/OPFClusterMatching.cpp
  # src/OPFHierarchicalClustering.cpp
  # src/OPFSpatialClustering.cpp
  # src/OPFSpectralClustering.cpp
  # src/OrientedExternPathFunction.cpp
  # src/OrientedInternPathFunction.cpp
  # src/PNMHeader.cpp
  # src/PathFunction.cpp
  # src/PixelInterpolation.cpp
  # src/Plotting.cpp
  # src/PreEuclideanDistanceFunction.cpp
  # src/RandomQueue.cpp
  # src/RealColor.cpp
  # src/Sample.cpp
  # src/SampleRandom.cpp
  # src/SampleUniform.cpp
  # src/SegmentationBackground.cpp
  # src/SegmentationBorder.cpp
  # src/SegmentationConnectedComponents.cpp
  # src/SegmentationGeoStar.cpp
  # src/SegmentationHysteresis.cpp
  # src/SegmentationIntensityThreshold.cpp
  # src/SegmentationMST.cpp
  # src/SegmentationOctants.cpp
  # src/SegmentationOtsuThreshold.cpp
  # src/SegmentationQuadrants.cpp
  # src/SegmentationSurface.cpp
  # src/SegmentationWatershed.cpp
  # src/Signal.cpp
  # src/SignalAccumulate.cpp
  # src/SignalEmptyBins.cpp
  # src/SignalEqualize.cpp
  # src/SignalHysteresis.cpp
  # src/SignalKeyPoints.cpp
  # src/SignalMedianFilter.cpp
  # src/SignalNormalize.cpp
  # src/SignalOtsuThreshold.cpp
  # src/SortingBinarySearch.cpp
  # src/SortingSort.cpp
  # src/SpatialFeature.cpp
  # src/SquareEuclideanDistanceFunction.cpp
  # src/StatisticsAverage.cpp
  # src/StatisticsBaddeley.cpp
  # src/StatisticsDice.cpp
  # src/StatisticsJaccard.cpp
  # src/StatisticsKappa.cpp
  # src/StatisticsMAD.cpp
  # src/StatisticsObsAgree.cpp
  # src/StatisticsPosNeg.cpp
  # src/StatisticsStdDev.cpp
  # src/SumPathFunction.cpp
  # # src/Superpixel.cpp --> por algum motivo, está desabilitado também no repositiório principal
  # src/Table.cpp
  # src/TransformEuclDist.cpp
  # src/TransformEuclDistInv.cpp
)
