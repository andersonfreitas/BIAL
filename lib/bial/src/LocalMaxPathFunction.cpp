/* Biomedical Image Analysis Library
 * See README file in the root instalation directory for more information.
 */

/**
 * @date 2012/Sep/19
 * @brief Local Max Path function to compute the initial path-values and propagated path-values in IFT algorithm.
 *        Used by River Bed algorithm.
 */

#ifndef BIALLOCALMAXPATHFUNCTION_C
#define BIALLOCALMAXPATHFUNCTION_C

#include "LocalMaxPathFunction.hpp"

#if defined ( BIAL_EXPLICIT_LIB ) && ( BIAL_LocalMaxPathFunction )
#define BIAL_EXPLICIT_LocalMaxPathFunction
#endif
#if defined ( BIAL_EXPLICIT_LocalMaxPathFunction ) || ( BIAL_IMPLICIT_BIN )

#include "BucketQueueElements.hpp"
#ifdef BIAL_DEBUG
#include "FileImage.hpp"
#endif
#include "Image.hpp"

/* Implementation ***************************************************************************************************** */

namespace Bial {

  template< template< class D > class C, class D >
  LocalMaxPathFunction< C, D >::LocalMaxPathFunction( ) try :
    PathFunction< C, D >( ) {
    }
  catch( std::bad_alloc &e ) {
    std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Memory allocation error." ) );
    throw( std::runtime_error( msg ) );
  }
  catch( std::runtime_error &e ) {
    std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Runtime error." ) );
    throw( std::runtime_error( msg ) );
  }
  catch( const std::out_of_range &e ) {
    std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Out of range exception." ) );
    throw( std::out_of_range( msg ) );
  }
  catch( const std::logic_error &e ) {
    std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Empty kernel." ) );
    throw( std::logic_error( msg ) );
  }

  template< template< class D > class C, class D >
  void LocalMaxPathFunction< C, D >::Initialize( C< D > &init_value, C< int > *init_label, C< int > *init_predecessor,
                                                 bool sequential_label ) {
    try {
      PathFunction< C, D >::Initialize( init_value, init_label, init_predecessor, sequential_label );
    }
    catch( std::bad_alloc &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Memory allocation error." ) );
      throw( std::runtime_error( msg ) );
    }
    catch( std::runtime_error &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Runtime error." ) );
      throw( std::runtime_error( msg ) );
    }
    catch( const std::out_of_range &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Out of range exception." ) );
      throw( std::out_of_range( msg ) );
    }
    catch( const std::logic_error &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Logic Error." ) );
      throw( std::logic_error( msg ) );
    }
  }

  template< template< class D > class C, class D >
  bool LocalMaxPathFunction< C, D >::RemoveSimple( size_t index, BucketState state ) {
    try {
      COMMENT( "Removing element.", 3 );
      return( true );
    }
    catch( std::bad_alloc &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Memory allocation error." ) );
      throw( std::runtime_error( msg ) );
    }
    catch( std::runtime_error &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Runtime error." ) );
      throw( std::runtime_error( msg ) );
    }
    catch( const std::out_of_range &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Out of range exception." ) );
      throw( std::out_of_range( msg ) );
    }
    catch( const std::logic_error &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Logic Error." ) );
      throw( std::logic_error( msg ) );
    }
  }

  template< template< class D > class C, class D >
  bool LocalMaxPathFunction< C, D >::RemoveLabel( size_t index, BucketState state ) {
    try {
      COMMENT( "Removing element.", 3 );
      if( state == BucketState::INSERTED ) {
        this->label->operator()( index ) = this->next_label;
        ++( this->next_label );
      }
      return( true );
    }
    catch( std::bad_alloc &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Memory allocation error." ) );
      throw( std::runtime_error( msg ) );
    }
    catch( std::runtime_error &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Runtime error." ) );
      throw( std::runtime_error( msg ) );
    }
    catch( const std::out_of_range &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Out of range exception." ) );
      throw( std::out_of_range( msg ) );
    }
    catch( const std::logic_error &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Logic Error." ) );
      throw( std::logic_error( msg ) );
    }
  }

  template< template< class D > class C, class D >
  inline bool LocalMaxPathFunction< C, D >::Capable( int index, int adj_index, BucketState adj_state ) {
    try {
      return( ( adj_state == BucketState::NOT_VISITED ) || ( adj_state == BucketState::INSERTED ) );
    }
    catch( std::bad_alloc &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Memory allocation error." ) );
      throw( std::runtime_error( msg ) );
    }
    catch( std::runtime_error &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Runtime error." ) );
      throw( std::runtime_error( msg ) );
    }
    catch( const std::out_of_range &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Out of range exception." ) );
      throw( std::out_of_range( msg ) );
    }
    catch( const std::logic_error &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Logic Error." ) );
      throw( std::logic_error( msg ) );
    }
  }

  template< template< class D > class C, class D >
  bool LocalMaxPathFunction< C, D >::Propagate( int index, int adj_index ) {
    try {
      return( true );
    }
    catch( std::bad_alloc &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Memory allocation error." ) );
      throw( std::runtime_error( msg ) );
    }
    catch( std::runtime_error &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Runtime error." ) );
      throw( std::runtime_error( msg ) );
    }
    catch( const std::out_of_range &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Out of range exception." ) );
      throw( std::out_of_range( msg ) );
    }
    catch( const std::logic_error &e ) {
      std::string msg( e.what( ) + std::string( "\n" ) + BIAL_ERROR( "Logic Error." ) );
      throw( std::logic_error( msg ) );
    }
  }

  template< template< class D > class C, class D >
  bool LocalMaxPathFunction< C, D >::Increasing( ) {
    return( false );
  }

#ifdef BIAL_EXPLICIT_LocalMaxPathFunction

  template class LocalMaxPathFunction< Image, int >;
  template class LocalMaxPathFunction< Image, llint >;
  template class LocalMaxPathFunction< Image, float >;
  template class LocalMaxPathFunction< Image, double >;

  template class LocalMaxPathFunction< Vector, llint >;
  template class LocalMaxPathFunction< Vector, int >;
  template class LocalMaxPathFunction< Vector, float >;
  template class LocalMaxPathFunction< Vector, double >;

  template class LocalMaxPathFunction< Matrix, int >;
  template class LocalMaxPathFunction< Matrix, llint >;
  template class LocalMaxPathFunction< Matrix, float >;
  template class LocalMaxPathFunction< Matrix, double >;

#endif

}

#endif

#endif
