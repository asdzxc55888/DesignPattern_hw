#include <gtest/gtest.h>
#include "ut_book.h"
#include "ut_collection.h"
#include "ut_iterator.h"
#include "ut_library.h"

int main( int argc , char **argv )
{
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS( ) ;
}
