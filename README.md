# RN新工程导入插件配置说明
## 创建一个新的工程
``` shell
#创建新工程
react-native init YoumeSDKRNDemo
```

## 配置Android 插件
- Android Studio 需要安装NDK
- 拷贝`SDK`文件夹到工程根目录，本Demo是在`YoumeSDKRNDemo/SDK`
- 拷贝`yimrn` 文件夹到android工程根目录，本Demo是在`YoumeSDKRNDemo/android/yimrn`
- 拷贝`CMakeLists.txt` 到 `android/app/CMakeLists.txt`
- 修改`android/app/build.gradle`，在 `defaultConfig` 段的末尾添加：
``` xml
    ndk {
            abiFilters "armeabi-v7a", "x86"
        }
        externalNativeBuild {
            cmake {
                cppFlags "-std=c++11 -frtti -fexceptions -llog"
                arguments "-DANDROID_TOOLCHAIN=clang", "-DANDROID_STL=c++_static"
            }
    }
```
- 修改`android/app/build.gradle`，在 `defaultConfig` 段的平级添加：
``` xml
    externalNativeBuild {
        cmake {
            path "CMakeLists.txt"
        }
    }
```

- 修改`android/app/build.gradle`，在 `dependencies` 添加：
``` xml
    implementation project(':yimrn')
```

- 修改`android/settings.gradle`，在`include ':app'`前添加：`include ':yimrn'`

- 在`MainApplication.java` 中添加插件注册：
``` xml
packages.add(new DjinniModulesPackage());
```

- 在`MainActivity.java`添加游密so加载代码：
``` java
  @Override
  protected void onCreate(Bundle savedInstanceState){
    IMEngine.init(this);
    YouMeManager.Init(this);
    super.onCreate(savedInstanceState);
  }
```

