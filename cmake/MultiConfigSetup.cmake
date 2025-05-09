if( NOT SET_UP_CONFIGURATIONS_DONE )
    set( SET_UP_CONFIGURATIONS_DONE TRUE )

    # No reason to set CMAKE_CONFIGURATION_TYPES if it's not a multiconfig generator
    # Also no reason mess with CMAKE_BUILD_TYPE if it's a multiconfig generator.
    get_property( isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG )
    if( isMultiConfig )
        set( CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE ) 
    else( )
        if( NOT CMAKE_BUILD_TYPE )
            message( "Defaulting to release build." )
            set( CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE )
        endif( )

        set_property( CACHE CMAKE_BUILD_TYPE PROPERTY HELPSTRING "Choose the type of build" )
        set_property( CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug;Release" )
    endif( )

endif( )