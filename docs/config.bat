REM x86, x64, x86_x64
SET "TARGET_ARCH=x86"
SET "TARGET_VER=5.12.0"
SET "SRC_DIR=%~dp0src"
SET "INSTALL_DIR=%~dp0msvc2017_static"
REM Static Qt
SET "EXTRA_CONFIG=-release -static -optimize-size -no-zlib -no-libjpeg -no-freetype -no-harfbuzz -skip qt3d -skip qtactiveqt -skip qtandroidextras -skip qtcanvas3d -skip qtcharts -skip qtconnectivity -skip qtdatavis3d -skip qtdeclarative -skip qtdoc -skip qtgamepad -skip qtgraphicaleffects -skip qtimageformats -skip qtlocation -skip qtmacextras -skip qtmultimedia -skip qtnetworkauth -skip qtpurchasing -skip qtquickcontrols -skip qtquickcontrols2 -skip qtremoteobjects -skip qtscript -skip qtscxml -skip qtsensors -skip qtserialbus -skip qtserialport -skip qtspeech -skip qttools -skip qttranslations -skip qtvirtualkeyboard -skip qtwayland -skip qtwebchannel -skip qtwebengine -skip qtwebglplugin -skip qtwebsockets -skip qtwebview -skip qtx11extras -skip qtxmlpatterns -no-feature-calendarwidget -no-feature-colordialog -no-feature-commandlinkbutton -no-feature-concurrent -no-feature-datetimeedit -no-feature-dial -no-feature-dockwidget -no-feature-fontcombobox -no-feature-fontdialog -no-feature-future -no-feature-gestures -no-feature-im -no-feature-keysequenceedit -no-feature-lcdnumber -no-feature-mdiarea -no-feature-pdf -no-feature-progressdialog -no-feature-sha3-fast -no-feature-splashscreen -no-feature-statusbar -no-feature-statustip -no-feature-syntaxhighlighter -no-feature-textodfwriter -no-feature-tuiotouch -no-feature-undocommand -no-feature-undogroup -no-feature-undostack -no-feature-undoview -no-feature-whatsthis -no-feature-wizard -no-feature-contextmenu -no-feature-effects -no-feature-errormessage -no-feature-mainwindow -no-feature-toolbar -no-feature-toolbox -no-feature-printdialog -no-feature-printer -no-feature-printpreviewdialog -no-feature-printpreviewwidget -no-feature-imageformatplugin -no-feature-cups -no-feature-iconv -no-feature-graphicseffect -no-feature-sharedmemory -no-feature-processenvironment -no-feature-process -no-feature-filesystemwatcher -no-feature-filesystemiterator -no-feature-movie -no-feature-imageformat_bmp -no-feature-imageformat_ppm -no-feature-imageformat_xbm -no-feature-multiprocess -no-feature-treewidget -no-feature-tablewidget -no-feature-imageformat_jpeg -no-feature-image_heuristic_mask -no-feature-image_text -no-feature-sqlmodel -no-feature-paint_debug -no-feature-tabbar -no-feature-tabwidget -no-feature-textbrowser -no-feature-sessionmanager -no-feature-picture -no-feature-desktopservices -no-feature-stringlistmodel -no-feature-statemachine -no-feature-timezone -no-feature-datetimeparser -no-feature-columnview -no-feature-tableview -no-feature-datawidgetmapper -no-feature-completer -no-feature-fscompleter -no-feature-listwidget -no-feature-resizehandler -no-feature-rubberband -no-feature-sizegrip -no-feature-systemsemaphore -no-feature-tabletevent"
REM Dynamic Qt
REM SET "EXTRA_CONFIG=-release -shared -optimize-size -ltcg -no-zlib -no-libjpeg -no-freetype -no-harfbuzz -skip qt3d -skip qtactiveqt -skip qtandroidextras -skip qtcanvas3d -skip qtcharts -skip qtconnectivity -skip qtdatavis3d -skip qtdeclarative -skip qtdoc -skip qtgamepad -skip qtgraphicaleffects -skip qtimageformats -skip qtlocation -skip qtmacextras -skip qtmultimedia -skip qtnetworkauth -skip qtpurchasing -skip qtquickcontrols -skip qtquickcontrols2 -skip qtremoteobjects -skip qtscript -skip qtscxml -skip qtsensors -skip qtserialbus -skip qtserialport -skip qtspeech -skip qttools -skip qttranslations -skip qtvirtualkeyboard -skip qtwayland -skip qtwebchannel -skip qtwebengine -skip qtwebglplugin -skip qtwebsockets -skip qtwebview -skip qtx11extras -skip qtxmlpatterns -no-feature-calendarwidget -no-feature-colordialog -no-feature-commandlinkbutton -no-feature-concurrent -no-feature-datetimeedit -no-feature-dial -no-feature-dockwidget -no-feature-fontcombobox -no-feature-fontdialog -no-feature-future -no-feature-gestures -no-feature-im -no-feature-keysequenceedit -no-feature-lcdnumber -no-feature-mdiarea -no-feature-pdf -no-feature-progressdialog -no-feature-sha3-fast -no-feature-splashscreen -no-feature-statusbar -no-feature-statustip -no-feature-syntaxhighlighter -no-feature-textodfwriter -no-feature-tuiotouch -no-feature-undocommand -no-feature-undogroup -no-feature-undostack -no-feature-undoview -no-feature-whatsthis -no-feature-wizard -no-feature-contextmenu -no-feature-effects -no-feature-errormessage -no-feature-mainwindow -no-feature-toolbar -no-feature-toolbox -no-feature-printdialog -no-feature-printer -no-feature-printpreviewdialog -no-feature-printpreviewwidget -no-feature-imageformatplugin -no-feature-cups -no-feature-iconv -no-feature-graphicseffect -no-feature-sharedmemory -no-feature-processenvironment -no-feature-process -no-feature-filesystemwatcher -no-feature-filesystemiterator -no-feature-movie -no-feature-imageformat_bmp -no-feature-imageformat_ppm -no-feature-imageformat_xbm -no-feature-multiprocess -no-feature-treewidget -no-feature-tablewidget -no-feature-imageformat_jpeg -no-feature-image_heuristic_mask -no-feature-image_text -no-feature-sqlmodel -no-feature-paint_debug -no-feature-tabbar -no-feature-tabwidget -no-feature-textbrowser -no-feature-sessionmanager -no-feature-picture -no-feature-desktopservices -no-feature-stringlistmodel -no-feature-statemachine -no-feature-timezone -no-feature-datetimeparser -no-feature-columnview -no-feature-tableview -no-feature-datawidgetmapper -no-feature-completer -no-feature-fscompleter -no-feature-listwidget -no-feature-resizehandler -no-feature-rubberband -no-feature-sizegrip -no-feature-systemsemaphore -no-feature-tabletevent"
