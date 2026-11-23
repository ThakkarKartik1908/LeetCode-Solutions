class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int newcolor,
             int orgcolor) {
        int m = image.size();
        int n = image[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n || image[i][j] == newcolor ||
            image[i][j] != orgcolor) {
            return;
        }

        image[i][j] = newcolor;
        dfs(image, i - 1, j, newcolor, orgcolor); // top
        dfs(image, i, j + 1, newcolor, orgcolor); // right
        dfs(image, i + 1, j, newcolor, orgcolor); // bottom
        dfs(image, i, j - 1, newcolor, orgcolor); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newcolor) {
        dfs(image, sr, sc, newcolor, image[sr][sc]);
        return image;
    }
};