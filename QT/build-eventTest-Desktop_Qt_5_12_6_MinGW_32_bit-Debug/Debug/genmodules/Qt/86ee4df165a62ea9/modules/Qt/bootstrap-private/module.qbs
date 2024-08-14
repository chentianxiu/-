import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Bootstrap"
    Depends { name: "Qt"; submodules: []}

    architectures: ["x86"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["user32","ole32","advapi32","shell32","netapi32","uuid","z"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5Bootstrapd"
    libNameForLinkerRelease: "Qt5Bootstrap"
    libFilePathDebug: undefined
    libFilePathRelease: "D:/QT/5.12.6/mingw73_32/lib/libQt5Bootstrap.a"
    pluginTypes: []
    moduleConfig: ["lex","yacc","depend_includepath","testcase_targets","import_qpa_plugin","windows","qt_build_extra","file_copies","qmake_use","qt","warn_on","release","link_prl","debug_and_release","precompile_header","release","no_plugin_manifest","win32","mingw","gcc","copy_dir_files","sse2","aesni","sse3","ssse3","sse4_1","sse4_2","avx","avx2","avx512f","avx512bw","avx512cd","avx512dq","avx512er","avx512ifma","avx512pf","avx512vbmi","avx512vl","compile_examples","f16c","largefile","optimize_debug","precompile_header","rdrnd","shani","x86SimdAlways","prefix_build","force_independent","utf8_source","create_prl","link_prl","prepare_docs","qt_docs_targets","no_private_qt_headers_warning","QTDIR_build","qt_example_installs","exceptions_off","testcase_exceptions","warning_clean","release","ReleaseBuild","Release","build_pass","minimal_syncqt","internal_module","force_bootstrap","gc_binaries","no_core_dep","static","relative_qt_rpath","git_build","qmake_cache","target_qt","c++11","strict_c++","c++14","c++1z","c99","c11","need_fwd_pri","qt_install_module","skip_target_version_ext","compiler_supports_fpmath","release","ReleaseBuild","Release","build_pass","have_target","staticlib","exclusive_builds","no_autoqmake","thread"]
    cpp.defines: ["QT_BOOTSTRAP_LIB","QT_VERSION_STR=\\\"\\\\\\\"5.12.6\\\\\\\"\\\"","QT_VERSION_MAJOR=5","QT_VERSION_MINOR=12","QT_VERSION_PATCH=6","QT_BOOTSTRAPPED","QT_NO_CAST_TO_ASCII"]
    cpp.includePaths: ["D:/QT/5.12.6/mingw73_32/include","D:/QT/5.12.6/mingw73_32/include/QtCore","D:/QT/5.12.6/mingw73_32/include/QtCore/5.12.6","D:/QT/5.12.6/mingw73_32/include/QtCore/5.12.6/QtCore","D:/QT/5.12.6/mingw73_32/include/QtXml","D:/QT/5.12.6/mingw73_32/include/QtXml/5.12.6","D:/QT/5.12.6/mingw73_32/include/QtXml/5.12.6/QtXml"]
    cpp.libraryPaths: ["C:/openssl/lib","C:/Utils/my_sql/mysql-5.6.11-win32/lib","C:/Utils/postgresql/pgsql/lib"]
    isStaticLibrary: true
Group {
        files: [Qt["bootstrap-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
