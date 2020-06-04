### gitconst:
 * LOP_MAX -> số lớp tối đa trong ds  

### struct Lop: gồm các thuộc tính của 1 lớp  
  
### class LOPTC: DSTT (mảng con trỏ) 
 * n -> số lớp trong ds  
 * stt -> để tăng thuộc tính malop tự động  
 * node -> con trỏ trỏ vào ds các lớp   

### function:  
 * khoiTao DS -> n=0, stt=0  
 * isFull -> ktra ds đầy  
 * isEmpty -> ktra ds rỗng  
 * insertLast(Lop) -> thêm lớp vào cuối ds  
 * insertOrder(Lop,int) -> thêm lớp vào ds theo vị trí (thêm vào đầu hoặc giữa ds)  
 * int search(int) -> tìm lớp theo mã lớp, trả về vị trí lớp, k có trong ds trả về -1  
 * nhapDS() -> nếu ds ko rỗng thì xóa hết DS - khởi tạo DS - nhập từng lớp  
 * themLop(Lop,int) -> thêm lớp theo vị trí:  
    * pos<0 -> thêm đầu  
    * pos>n -> thêm cuối  
    * conlai -> thêm theo vị trí  
 * xoaLop(int) -> xóa lớp theo mã lớp  
 * xoaDS -> xóa toàn bộ ds
