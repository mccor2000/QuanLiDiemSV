### Khởi tạo 1 Node
    Node<TypeData> <tên biến>;

    ví dụ:

    Node<SinhVien> tmp;

# Method:
    tmp.set_data(val)
    tmp.set_next(pointer)
    tmp.get_data();
    tmp.get_next();



### LinkedList

# Khởi tạo : 
    LinkedList<TypeData> <tên list>
    
    Ví dụ : Có TypeData = SinhVien;

    LinkedList<SinhVien> list;

# Method :
   * list.head() return Head node.
   * list.tail() return Tail node.
   * list.push_back(SinhVien val) adding val phía sau list.
   * list.push_fron(Sinh vien val) adding val phía trước list.
   * list.insert(Sinh vien val, int position) chèn 1 val vào sau vị trí nhập vào.
   * list.remove(int position) xoá 1 node tại vị trí nhập vào.
   