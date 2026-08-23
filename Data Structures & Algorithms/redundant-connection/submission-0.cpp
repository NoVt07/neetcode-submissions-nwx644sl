class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // Đề bài không cho N trực tiếp, nhưng ta biết đồ thị có 1 cạnh thừa,
        // suy ra số đỉnh n đúng bằng số lượng cạnh.
        int n = edges.size();
        
        // Khởi tạo mảng parent kích thước n + 1 (vì các đỉnh được đánh số từ 1 đến n)
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i; // Ban đầu mỗi đỉnh tự làm đại diện cho chính nó
        }
        
        // Duyệt qua từng cạnh trong mảng edges
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            // Tìm đại diện của 2 đỉnh
            int rootU = find(u, parent);
            int rootV = find(v, parent);
            
            // Nếu chúng đã chung một đại diện (nghĩa là đã có đường nối từ trước)
            // Việc thêm cạnh này vào sẽ tạo ra chu trình!
            if (rootU == rootV) {
                // Trả về ngay cạnh đang xét vì nó là cạnh gây ra vòng lặp
                // (và do ta duyệt từ trái sang phải, đây sẽ là cạnh trễ nhất)
                return edge; 
            }
            
            // Nếu khác đại diện, tiến hành gộp nhóm (Union)
            parent[rootU] = rootV;
        }
        
        return {}; // Mặc định phải có (dù thực tế với input hợp lệ thì vòng lặp luôn return trước)
    }

private:
    // Hàm tìm kiếm kết hợp Nén đường (Path Compression)
    int find(int i, vector<int>& parent) {
        if (parent[i] == i) {
            return i;
        }
        // Gán trực tiếp đại diện cao nhất cho đỉnh hiện tại để tối ưu thời gian
        return parent[i] = find(parent[i], parent);
    }
};