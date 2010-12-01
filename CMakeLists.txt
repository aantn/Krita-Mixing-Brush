set(kritaminimalpaintop_PART_SRCS
    minimal_paintop_plugin.cpp
    kis_minimal_paintop.cpp
    kis_minimal_paintop_options.cpp
    kis_minimal_paintop_settings.cpp
    kis_minimal_paintop_settings_widget.cpp
    )

kde4_add_ui_files(kritaminimalpaintop_PART_SRCS wdgminimaloptions.ui )

kde4_add_plugin(kritaminimalpaintop ${kritaminimalpaintop_PART_SRCS})


target_link_libraries(kritaminimalpaintop kritalibpaintop)

install(TARGETS kritaminimalpaintop  DESTINATION ${PLUGIN_INSTALL_DIR})


########### install files ###############

install( FILES  kritaminimalpaintop.desktop  DESTINATION ${SERVICES_INSTALL_DIR})
install( FILES
    krita-minimal.png DESTINATION ${DATA_INSTALL_DIR}/krita/images)

