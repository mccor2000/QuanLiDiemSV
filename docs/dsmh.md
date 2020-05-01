### Class DanhSachMonHoc  
# Khởi tạo: 
```c++
#include "library.h"
DanhSachMonHoc ds;
```
# Thêm môn học:
```c++
// Khởi tạo môn học 
// MAMH: char[10], TENMH: char[50], STCLT: int, STCTH: int 
MonHoc * new_mh = new MonHoc(<MAMH>, <TENMH>, <STCLT>, <STCTH>);
// Thêm môn học 
ds.insert(new_mh);
```

# Tìm môn học:
```c++
MonHoc * mh;
mh = ds.search(<ten_mh>); 
```
# Xóa môn học: 
```c++
//...Tìm môn học:
ds.remove(mh);
```
# Duyệt ds môn học:
```c++
ds.enumerate();
```
