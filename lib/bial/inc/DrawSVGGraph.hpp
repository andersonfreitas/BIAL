/* Biomedical Image Analysis Library
 * See README file in the root instalation directory for more information.
 */

/**
 * @date 2014/Mar/14
 * @brief Functions to draw graphs in SVG file format.
 */

#include "Common.hpp"
#include "Vector.hpp"

#ifndef BIALDRAWSVGGRAPH_H
#define BIALDRAWSVGGRAPH_H

namespace Bial {

  template< class D >
  class Image;
  class Adjacency;

  /**
   * @date 2015/Aug/30
   * @param vertex: Lines image containing vertices with their weight.
   * @param adj: An adjacency relation to compute the arcs.
   * @param filename: File to write results.
   * @return none.
   * @brief Writes the directed graph in SVG format into a file.
   * @warning none.
   */
  template< class D >
  void SVGDGraph( const Image< D > &vertex, const Adjacency &adj, const std::string &filename );

  /**
   * @date 2015/Aug/30
   * @param vertex: Lines image containing vertices with their weight.
   * @param seed: A boolean Vector with the same size of the vertex image indicating if each element is a seed or not.
   * @param adj: An adjacency relation to compute the arcs.
   * @param filename: File to write results.
   * @return none.
   * @brief Writes the directed graph in SVG format into a file.
   * @warning none.
   */
  template< class D >
  void SVGDGraph( const Image< D > &vertex, const Vector< bool > &seed, const Adjacency &adj,
                  const std::string &filename );

  /**
   * @date 2015/Aug/30
   * @param vertex: Lines image containing vertices with their weight.
   * @param seed: A boolean Vector with the same size of the vertex image indicating if each element is a seed or not.
   * @param label: The label of the objects. Must have the same size as vertex image. Converted to colors automatically.
   * @param adj: An adjacency relation to compute the arcs.
   * @param filename: File to write results.
   * @return none.
   * @brief Writes the directed graph in SVG format into a file.
   * @warning none.
   */
  template< class D >
  void SVGDGraph( const Image< D > &vertex, const Vector< bool > &seed, const Image< int > &label,
                  const Adjacency &adj, const std::string &filename );

  /**
   * @date 2015/Aug/30
   * @param cost: The cost of the vertices.
   * @param pred: The predecessor in the forest of each element. -1 means the element is a root.
   * @param label: The label of the vertices. Must have the same size as vertex image. Converted to colors automatically.
   * @param filename: File to write results.
   * @return none.
   * @brief Writes the directed graph in SVG format into a file.
   * @warning none.
   */
  template< class D >
  void SVGDForest( const Image< D > &cost, const Image< int > &pred, const Image< int > &label,
                   const std::string &filename );

}

#include "DrawSVGGraph.cpp"

#endif