import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "RemoteObjects"
    Depends { name: "Qt"; submodules: ["core","network"]}

    architectures: ["x86"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5RemoteObjectsd"
    libNameForLinkerRelease: "Qt5RemoteObjects"
    libFilePathDebug: "D:/QT/5.12.6/mingw73_32/lib/libQt5RemoteObjectsd.a"
    libFilePathRelease: "D:/QT/5.12.6/mingw73_32/lib/libQt5RemoteObjects.a"
    pluginTypes: []
    moduleConfig: ["lex","yacc","depend_includepath","testcase_targets","import_plugins","import_qpa_plugin","windows","qt_build_extra","file_copies","qmake_use","qt","warn_on","release","link_prl","debug_and_release","shared","release","no_plugin_manifest","win32","mingw","gcc","copy_dir_files","sse2","aesni","sse3","ssse3","sse4_1","sse4_2","avx","avx2","avx512f","avx512bw","avx512cd","avx512dq","avx512er","avx512ifma","avx512pf","avx512vbmi","avx512vl","compile_examples","f16c","largefile","optimize_debug","rdrnd","shani","x86SimdAlways","prefix_build","force_independent","utf8_source","create_prl","link_prl","prepare_docs","qt_docs_targets","no_private_qt_headers_warning","QTDIR_build","qt_example_installs","exceptions_off","testcase_exceptions","qt_example_installs","release","ReleaseBuild","Release","build_pass","release","ReleaseBuild","Release","build_pass","relative_qt_rpath","git_build","qmake_cache","target_qt","c++11","strict_c++","c++14","c++1z","c99","c11","qt_install_headers","need_fwd_pri","qt_install_module","debug_and_release","build_all","create_cmake","skip_target_version_ext","compiler_supports_fpmath","create_pc","c++11","release","ReleaseBuild","Release","build_pass","have_target","dll","exclusive_builds","no_autoqmake","thread","moc","resources"]
    cpp.defines: ["QT_REMOTEOBJECTS_LIB"]
    cpp.includePaths: ["D:/QT/5.12.6/mingw73_32/include","D:/QT/5.12.6/mingw73_32/include/QtRemoteObjects"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["remoteobjects"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
