set(kritamixingpaintop_PART_SRCS
    mixing_paintop_plugin.cpp
    kis_mixing_paintop.cpp
    kis_mixingop_option.cpp
    kis_mixing_paintop_settings.cpp
    kis_mixing_paintop_settings_widget.cpp
    mixing_brush.cpp	
    )

kde4_add_ui_files(kritamixingpaintop_PART_SRCS wdgmixingoptions.ui )

kde4_add_plugin(kritamixingpaintop ${kritamixingpaintop_PART_SRCS})


target_link_libraries(kritamixingpaintop kritalibpaintop)

install(TARGETS kritamixingpaintop  DESTINATION ${PLUGIN_INSTALL_DIR})


########### install files ###############

install( FILES  kritamixingpaintop.desktop  DESTINATION ${SERVICES_INSTALL_DIR})
install( FILES
    krita-mixing.png DESTINATION ${DATA_INSTALL_DIR}/krita/images)
install( FILES  3d-pencil.obj DESTINATION ${DATA_INSTALL_DIR}/krita/brushmodels )
install( FILES  3d-pencil.mtl DESTINATION ${DATA_INSTALL_DIR}/krita/brushmodels )


