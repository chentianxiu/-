import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Bootstrap"
    Depends { name: "Qt"; submodules: []}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["user32","ole32","advapi32","shell32","netapi32"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5Bootstrapd.lib"
    libNameForLinkerRelease: "Qt5Bootstrap.lib"
    libFilePathDebug: undefined
    libFilePathRelease: "D:/QT/5.12.6/msvc2015_64/lib/Qt5Bootstrap.lib"
    pluginTypes: []
    moduleConfig: ["lex","yacc","depend_includepath","testcase_targets","import_qpa_plugin","windows","qt_build_extra","file_copies","qmake_use","qt","warn_on","release","link_prl","flat","debug_and_release","precompile_header","autogen_precompile_source","embed_manifest_dll","embed_manifest_exe","release","no_plugin_manifest","win32","msvc","copy_dir_files","sse2","aesni","sse3","ssse3","sse4_1","sse4_2","avx","avx2","compile_examples","f16c","force_debug_info","largefile","precompile_header","rdrnd","shani","x86SimdAlways","prefix_build","force_independent","utf8_source","create_prl","link_prl","prepare_docs","qt_docs_targets","no_private_qt_headers_warning","QTDIR_build","qt_example_installs","exceptions_off","testcase_exceptions","warning_clean","release","ReleaseBuild","Release","build_pass","c++11","win32-msvc2015","minimal_syncqt","internal_module","force_bootstrap","gc_binaries","static","relative_qt_rpath","git_build","qmake_cache","target_qt","c++11","strict_c++","need_fwd_pri","qt_install_module","skip_target_version_ext","release","ReleaseBuild","Release","build_pass","have_target","staticlib","exclusive_builds","debug_info","no_autoqmake","thread"]
    cpp.defines: ["QT_BOOTSTRAP_LIB","QT_VERSION_STR=\\\"\\\\\\\"5.12.6\\\\\\\"\\\"","QT_VERSION_MAJOR=5","QT_VERSION_MINOR=12","QT_VERSION_PATCH=6","QT_BOOTSTRAPPED","QT_NO_CAST_TO_ASCII"]
    cpp.includePaths: ["D:/QT/5.12.6/msvc2015_64/include","D:/QT/5.12.6/msvc2015_64/include/QtCore","D:/QT/5.12.6/msvc2015_64/include/QtCore/5.12.6","D:/QT/5.12.6/msvc2015_64/include/QtCore/5.12.6/QtCore","D:/QT/5.12.6/msvc2015_64/include/QtXml","D:/QT/5.12.6/msvc2015_64/include/QtXml/5.12.6","D:/QT/5.12.6/msvc2015_64/include/QtXml/5.12.6/QtXml"]
    cpp.libraryPaths: ["C:/openssl/lib","C:/Utils/my_sql/mysql-5.6.11-winx64/lib","C:/Utils/postgresql/pgsql/lib"]
    isStaticLibrary: true
Group {
        files: [Qt["bootstrap-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
