# cmake --build build "-DCMAKE_TOOLCHAIN_FILE=/Users/angular/workspace/vcpkg/scripts/buildsystems/vcpkg.cmake"
###
 # @Author: yaohengfeng 1921934563@qq.com
 # @Date: 2023-06-09 16:43:20
 # @LastEditors: yaohengfeng 1921934563@qq.com
 # @LastEditTime: 2023-06-14 13:52:33
 # @FilePath: /cmake-hid-handle/build.sh
 # @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
### 
# ###
#  # @Author: yaohengfeng 1921934563@qq.com
#  # @Date: 2023-06-09 16:43:20
#  # @LastEditors: yaohengfeng 1921934563@qq.com
#  # @LastEditTime: 2023-06-14 10:55:49
#  # @FilePath: /cmake-hid-handle/build.sh
#  # @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
# ### 

# cmake --build build --config release

cd ./build 

cmake .. -DCMAKE_TOOLCHAIN_FILE=/Users/angular/workspace/vcpkg/scripts/buildsystems/vcpkg.cmake && cmake --build .

