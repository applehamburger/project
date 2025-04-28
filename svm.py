
import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC

# 生成更多数据点
def generate_data():
    X, y = make_blobs(n_samples=300, centers=2, random_state=42)
    return X, y

# SVM分类器训练和可视化
def train_and_visualize(X, y, C=1.0, test_size=0.1):
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=test_size, random_state=42)
    
    clf = SVC(kernel='linear', C=C)
    clf.fit(X_train, y_train)
    
    # 打印最佳参数配置
    print(f"最佳参数配置：Kernel=linear, C={C}")
    
    # 打印支持向量
    print("支持向量：")
    print(clf.support_vectors_)
    
    # 在数据集上绘制分类效果
    plt.figure(figsize=(10, 6))
    
    plt.scatter(X[:, 0], X[:, 1], c=y, cmap='viridis', marker='o', s=50)
    
    # 绘制支持向量
    plt.scatter(clf.support_vectors_[:, 0], clf.support_vectors_[:, 1], s=100, facecolors='none', edgecolors='k')
    
    # 绘制分割线
    w = clf.coef_[0]
    a = -w[0] / w[1]
    xx = np.linspace(np.min(X[:, 0]), np.max(X[:, 0]))
    yy = a * xx - (clf.intercept_[0]) / w[1]
    
    plt.plot(xx, yy, 'k-')
    
    plt.xlabel('Feature 1')
    plt.ylabel('Feature 2')
    plt.title('Linear SVM Classification Result')
    
    plt.show()

# 生成数据
X, y = generate_data()

# 训练和可视化
train_and_visualize(X, y, C=1.0)
