file(REMOVE_RECURSE
  "tiny-renderer"
  "tiny-renderer.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/tiny-renderer.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
