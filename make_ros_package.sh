#!/bin/bash

dir=$(pwd)
echo $dir

package_name=$1

echo "Create package_name directory..."
mkdir $package_name

echo "Create files."

# hpp file template
template_hpp=$(sed "s/PackageName/$(tr '[:lower:]' '[:upper:]' <<<${package_name:0:1})${package_name:1}/g" template.hpp)

# cpp file template
template_cpp=$(sed -e "s/\package_name/$package_name/g" -e "s/PackageName/$(tr '[:lower:]' '[:upper:]' <<<${package_name:0:1})${package_name:1}/g" template.cpp)

# test file template
template_test=$(sed -e "s/\package_name/$package_name/g" -e "s/PackageName/$(tr '[:lower:]' '[:upper:]' <<<${package_name:0:1})${package_name:1}/g" template_test.cpp)

# cmake file template
template_cmake=$(sed "s/\package_name/$package_name/g" template.CMakeLists.txt)

template_xml=$(sed "s/\package_name/$package_name/g" template.package.xml)

template_md=$(cat template.Readme.md)

templeate_launch=$(sed "s/\package_name/$package_name/g" template.launch.xml)

cd $package_name

mkdir -p src/${package_name}
mkdir -p include/${package_name}
mkdir -p launch
mkdir -p test
echo "$template_test" >test/test_${package_name}.cpp
echo "$template_hpp" >include/${package_name}/${package_name}.hpp
echo "$template_cpp" >src/${package_name}/${package_name}.cpp
echo "$template_xml" >package.xml
echo "$template_cmake" >CMakeLists.txt
echo "$template_md" >Readme.md
echo "$templeate_launch" >launch/${package_name}.launch.xml
