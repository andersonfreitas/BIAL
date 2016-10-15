cmake_minimum_required(VERSION 2.8.5)

# set(CMAKE_C_COMPILER "/opt/intel/bin/icc")
# set(CMAKE_CXX_COMPILER "/opt/intel/bin/icpc")

# set(CMAKE_BUILD_TYPE Release)

add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DREAL_FLOAT -DBIAL_IMPLICIT_BIN")

set (CMAKE_EXPORT_COMPILE_COMMANDS 1)
# set (CMAKE_POSITION_INDEPENDENT_CODE TRUE)

project(bial-tst)

set(CMAKE_BUILD_TYPE Release)

aux_source_directory(test/src SOURCE_FILES)

find_package( ZLIB REQUIRED )
if ( ZLIB_FOUND )
    include_directories( ${ZLIB_INCLUDE_DIRS} )
endif( ZLIB_FOUND )

# liblsh
include_directories(lib/lsh/inc)
add_subdirectory(lib/lsh)

# libslic
# include_directories(lib/slic/inc)
# add_subdirectory(lib/slic)

# libbial
include_directories(lib/bial/inc lib/bial/src)
add_subdirectory(lib/bial)

link_libraries(${DEPS_LIBRARIES} -lm)

# Executables
set(PROGRAMS
  Adjacency-Displacement
  Adjacency-Gray
  AffineTransform-2D
  AffineTransform-3D
  Bit-Invert
  Bit-Operations
  Brain-CMeansClustering
  Brain-COG
  Brain-HeadTopSlice
  Brain-InhomogeneityCorrection
  Brain-IntensityCuts
  Brain-OPFClustering
  Brain-Segmentation
  Brain-SplitOPFClustering
  Brain-TissueThresholds
  Clustering-OPFDistance
  Color-CMeansClustering
  Color-RGBtoHSI
  DataSet-Validate
  Draw-Circle
  Draw-Line-3D
  Draw-Line
  Draw-SVGDGraph
  Draw-SVGForest
  Drawing
  Feature-Read
  Feature-Write
  File-ReadDir
  Filtering-AdaptiveAnisotropic
  Filtering-Anisotropic
  Filtering-Gaussian
  Filtering-Mean
  Filtering-Median
  Filtering-OptimalAnisotropic
  Gradient-AutoCanny
  Gradient-Canny
  Gradient-DirectionalSobel
  Gradient-Gabor
  Gradient-HoleClosing
  Gradient-Morphological
  Gradient-MultiScaleCanny
  Gradient-MultiScaleSizeCanny
  Gradient-MultiSubScaleCanny
  Gradient-ScaleCanny
  Gradient-Sobel
  Gradient-SuppressedSobel
  Heart-COG
  Heart-Segmentation
  Heart-SequencyLocation
  Hough-Circles
  Image-AND
  Image-AnisotropicDiffusionFiltering
  Image-BinaryMask
  Image-CMeansClustering
  Image-ColorBinaryMask
  Image-Compare
  Image-Convert
  Image-Copy
  Image-CutHorizontal
  Image-DicomRead
  Image-Diff
  Image-Dilate
  Image-Equalize
  Image-Erode
  Image-Flip
  Image-GetSlice
  Image-IFTWatershed
  Image-Merge
  Image-MinimumSpanningForest
  Image-Multiply
  Image-MultiplyMask
  Image-Print
  Image-ROI
  Image-Rotate_90
  Image-Sum
  ImageInterpolation-Isometric
  Insert-Inhomogeneity
  Kernel-Gabor
  Kernel-Gaussian
  Kernel-NormalizedGaussian
  Kernel-NormalizedSobel
  Kernel-Sobel
  LazyWalk
  LiveWire
  Lungs-Segmentation
  Lungs-Segmentation2
  MRI-CopyNiftiHeader
  MRI-Dimensions
  MRI-NiftiHeader
  MRI-Orientation
  MRI-SetNiftiHeader
  MRI-SetOffset
  MRI-Threshold
  MarchingCubes-Binary
  MarchingCubes-Clean
  MarchingCubes-ConvertToSTL
  Matrix-3DCompare
  Matrix-Cofactor
  Matrix-Determinant
  Matrix-Exceptions
  # Matrix-Gradient # requires Edge.hpp
  Matrix-Invert
  Matrix-Move
  Matrix-Multiplication
  Matrix-Read
  Matrix-Read_Write
  Matrix-Scalars
  Matrix-Sum
  Matrix-Time
  MultiImage-IO
  OPF-FeatureClustering
  OPF-Hierarchical
  OPF-ImageHierarchical
  OPF-KClustering
  OPF-LSH
  OPF-LSH_minimal
  OPF-LabelMatching
  PNM-Color
  PNM-Otsu
  PNM-Read
  PNM-Rotation
  PNM-Sum
  PNM-Write
  Plate-Finder
  Plate-Graphics
  Plate-Statistics
  Relaxometria
  RiverBed
  Segmentation-Background
  Segmentation-ConnectedComponents
  Segmentation-ConvertSeeds
  Segmentation-Disconnected
  Segmentation-Octants
  Segmentation-OrientedExternGeodesicStar
  Segmentation-OrientedInternGeodesicStar
  Segmentation-Quadrants
  Segmentation-Threshold
  Segmentation-Watershed
  Signal-Equalize
  Signal-Histogram
  Signal-Normalize
  Sorting-BucketQueue
  Sorting-BucketQueueMax
  Sorting-InfBucketQueue
  Sorting-QuickIndex
  Sorting-RandomQueueMedians
  Statistics-Accuracy
  Statistics-BorderValidate
  Statistics-EdgeCompareBaddeley
  Statistics-MAD
  Statistics-MultiClassLabeling
  # SuperPixel-Brain
  # SuperPixel-Image
  # SuperPixel-RiverBed
  Table-Print
  Transform-Euclidean
  Transform-InverseEuclidean
  Vector-Basic
)

foreach(PROGRAM ${PROGRAMS})
  add_executable(${PROGRAM} test/src/${PROGRAM}.cpp)
  target_link_libraries(${PROGRAM} ${ZLIB_LIBRARIES} bial lsh)
endforeach()
