import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QmlDevTools"
    Depends { name: "Qt"; submodules: ["core-private"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["$$[QT_HOST_LIBS]/Qt5Core.lib"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5QmlDevToolsd.lib"
    libNameForLinkerRelease: "Qt5QmlDevTools.lib"
    libFilePathDebug: undefined
    libFilePathRelease: "D:/QT/5.12.6/msvc2015_64/lib/Qt5QmlDevTools.lib"
    pluginTypes: []
    moduleConfig: ["lex","yacc","depend_includepath","testcase_targets","import_qpa_plugin","windows","qt_build_extra","file_copies","qmake_use","qt","warn_on","release","link_prl","flat","debug_and_release","precompile_header","autogen_precompile_source","embed_manifest_dll","embed_manifest_exe","release","no_plugin_manifest","win32","msvc","copy_dir_files","sse2","aesni","sse3","ssse3","sse4_1","sse4_2","avx","avx2","compile_examples","f16c","force_debug_info","largefile","precompile_header","rdrnd","shani","x86SimdAlways","prefix_build","force_independent","utf8_source","create_prl","link_prl","prepare_docs","qt_docs_targets","no_private_qt_headers_warning","QTDIR_build","qt_example_installs","exceptions_off","testcase_exceptions","warning_clean","python_available","release","ReleaseBuild","Release","build_pass","c++11","win32-msvc2015","release","ReleaseBuild","Release","build_pass","minimal_syncqt","internal_module","qmldevtools_build","generated_privates","qlalr","static","relative_qt_rpath","git_build","qmake_cache","target_qt","c++11","strict_c++","need_fwd_pri","qt_install_module","skip_target_version_ext","release","ReleaseBuild","Release","build_pass","have_target","staticlib","exclusive_builds","debug_info","no_autoqmake","thread","moc","resources"]
    cpp.defines: ["QT_QMLDEVTOOLS_LIB"]
    cpp.includePaths: ["D:/QT/5.12.6/msvc2015_64/include","D:/QT/5.12.6/msvc2015_64/include/QtQml","D:/QT/5.12.6/msvc2015_64/include/QtQml/5.12.6","D:/QT/5.12.6/msvc2015_64/include/QtQml/5.12.6/QtQml"]
    cpp.libraryPaths: ["C:/openssl/lib","C:/Utils/my_sql/mysql-5.6.11-winx64/lib","C:/Utils/postgresql/pgsql/lib"]
    isStaticLibrary: true
Group {
        files: [Qt["qmldevtools-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
