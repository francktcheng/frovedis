#ifndef CONFIG_HPP
#define CONFIG_HPP

//#define USE_THREAD
//#define USE_STD_RANDOM
//#if defined(_SX)
//#define USE_ORDERED_MAP
//#endif
//#if defined(_SX)
//#define USE_BOOST_HASH
//#endif

// zipped_unordered_map does not work
//#define USE_CEREAL_FOR_RPC
#define USE_CEREAL_FOR_EXRPC

#if defined(USE_CEREAL_FOR_RPC) || defined(USE_CEREAL_FOR_EXRPC)
#define USE_CEREAL
#endif
#if !defined(USE_CEREAL_FOR_RPC) || !defined(USE_CEREAL_FOR_EXRPC)
#define USE_BOOST_SERIALIZATION
#endif

// either of them need to be defined
//#define BIG_ENDIAN_FILE
#define LITTLE_ENDIAN_FILE

#endif
