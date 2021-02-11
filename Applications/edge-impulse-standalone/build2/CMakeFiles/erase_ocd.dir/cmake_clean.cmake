file(REMOVE_RECURSE
  "*"
  ".config.old"
  "App"
  "CMakeCache.txt"
  "CMakeDoxyfile.in"
  "CMakeDoxygenDefaults.cmake"
  "Doxyfile"
  "Thirdparty"
  "cmake_install.cmake"
  "dsp_fw-prefix"
  "dsp_src-prefix"
  "edge-impulse-standalone.bin"
  "edge-impulse-standalone.elf"
  "edge-impulse-standalone.elf.json"
  "edge-impulse-standalone.lss"
  "edge-impulse-standalone.map"
  "framework"
  "hw"
  "util
"
  "CMakeCache.txt"
  "CMakeFiles/erase_ocd"
  "CPackConfig.cmake"
  "CPackSourceConfig.cmake"
  "\\*.bin"
  "\\*.lss"
  "\\*.map"
  "\\.cmake"
  "_CPack_Packages"
  "cmake_install.cmake"
  "util"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/erase_ocd.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
