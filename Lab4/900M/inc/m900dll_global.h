#ifndef M900DLL_GLOBAL_H
#define M900DLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(M900DLL_LIBRARY)
#  define M900DLLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define M900DLLSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // M900DLL_GLOBAL_H
