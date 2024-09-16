# Learnings from Chapter 1: Neural Networks and Deep Learning
### Overview
In Chapter 1 of Michael Nielsen’s **"Neural Networks and Deep Learning"** I explored the foundational concepts of neural networks, including their structure, training, and the mathematics behind their operations. This chapter laid the groundwork for understanding how neural networks function and how they can be implemented to solve classification problems, such as digit recognition with the [MNIST dataset](https://github.com/mnielsen/neural-networks-and-deep-learning/tree/master/data). Download it ⬅️

### Key Concepts
**1. Neural Network Structure**

- **Layers:** Neural networks consist of an input layer, one or more hidden layers, and an output layer. Each layer is made up of neurons (nodes) that process information.

- **Weights and Biases:** Each connection between neurons has an associated weight, and each neuron has a bias. Weights and biases are adjusted during training to minimize the error of the network’s predictions.

- **Activation Function:** The activation function introduces non-linearity into the network, allowing it to learn complex patterns. The sigmoid function was used in this implementation.

**2. Feedforward Process**

- **Forward Propagation:** The process of passing input data through the network to obtain an output. Each layer applies a weighted sum of its inputs plus a bias, followed by an activation function.

- **Mathematical Operations:** The key operations involved are matrix multiplication for weights and bias addition, followed by the application of the activation function.

**3. Backpropagation**

- **Error Calculation:** Backpropagation involves calculating the error of the network’s predictions and propagating this error backward through the network to update weights and biases.

- **Gradient Descent:** The method used to minimize the error by adjusting the weights and biases in the direction that reduces the cost. The gradients are computed using the chain rule of calculus.

- **Cost Function:** The cost function measures the difference between the predicted output and the actual label. The derivative of the cost function with respect to the output activations is used to update the weights and biases.

**4. Training the Network**

- **Mini-Batch Gradient Descent:** The network is trained using mini-batches of data, which helps in efficiently updating weights and biases. The learning rate (eta) controls the step size of each update.

- **Epochs:** Training is performed over multiple epochs, where each epoch consists of processing all mini-batches and updating the network.

**5. Evaluation**

- **Accuracy Measurement:** After training, the network’s performance is evaluated on test data. Accuracy is calculated as the percentage of correctly classified test examples.

### Implementation by classical methods Details

- **Data Loading and Preprocessing:** I used pickle to load the MNIST dataset and performed preprocessing steps including normalization and one-hot encoding.

- **Neural Network Class:** Implemented a basic feedforward neural network with methods for forward propagation, backpropagation, and weight updates.

- **Activation and Derivative Functions:** Used the sigmoid function and its derivative to introduce non-linearity and compute gradients.

- **Training Procedure:** Applied mini-batch gradient descent to train the network and evaluate its performance.

# Comparing between Implementation Using classical Methods and PyTorch

I will compare the 2 implementations in 3 aspects of comparison:

### 1. Ease of use: 

**Without PyTorch:**

- **Complexity:** Implementing neural networks from scratch requires manually coding every aspect of the network, including forward propagation, backpropagation, weight updates, and optimization. This involves detailed understanding of linear algebra and calculus.

- **Error-Prone:** Manual implementations are prone to errors, especially with complex operations like gradient calculations and matrix manipulations.

- **Time-Consuming: Development and debugging can be significantly time-consuming. 

**With PyTorch:**

- **Simplicity:** PyTorch provides high-level abstractions and built-in functionalities for building and training neural networks. We only need to define the model architecture and training loop, while PyTorch handles the complexities of backpropagation and optimization.

- **Less Code:** PyTorch reduces the amount of code we need to write for defining and training models. This leads to more readable and maintainable code.

### 2. Performance:

**Without PyTorch:**

- **Optimization:** Manual implementations may not be optimized for performance. Operations are performed using basic Python and NumPy, which can be slower compared to optimized libraries.

- **Parallelism:** Lack of built-in support for GPU acceleration means computations are typically performed on the CPU, which can be a bottleneck for large models or datasets.

**With PyTorch:**

- **GPU Acceleration:** PyTorch supports GPU acceleration, significantly speeding up training and inference times for large models and datasets.

- **Optimized Operations:** PyTorch uses highly optimized backend libraries to perform tensor operations efficiently. This often results in better performance compared to manual implementations.

### 3. Flexibility

**Without PyTorch:**

- **Customization:** Allows for complete customization of the model and training process. You can experiment with novel algorithms or unusual architectures without restrictions imposed by a framework

**With PyTorch:**
- **Built-in Features:** PyTorch offers a wide range of built-in features such as advanced optimizers, loss functions, and layers. It also supports custom operations and layers with ease.

- **Community and Ecosystem:** PyTorch benefits from a large community and extensive ecosystem of pre-trained models, tutorials, and research papers. This makes it easier to find resources and solutions for various problems.
