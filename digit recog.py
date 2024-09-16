import pickle
import numpy as np

# Load data from .pkl file
def load_data_from_pkl(filename):
    with open('mnist.pkl', 'rb') as f:
        data = pickle.load(f, encoding='latin1')  # 'latin1' used to avoid decoding errors
    training_data, validation_data, test_data = data  # Unpack the three elements
    return training_data, test_data

# One-hot encode labels
def one_hot_encode(label):
    encoded = np.zeros((10, 1))
    encoded[label] = 1.0
    return encoded

# Preprocess the data (reshape, normalize, one-hot encode)
def preprocess_data(training_data, test_data):
    training_images, training_labels = training_data
    test_images, test_labels = test_data

    # Normalize and reshape the images
    training_images = np.array([np.reshape(x, (784, 1)) / 255.0 for x in training_images])
    test_images = np.array([np.reshape(x, (784, 1)) / 255.0 for x in test_images])

    # Convert labels to one-hot encoding for training
    training_labels = np.array([one_hot_encode(y) for y in training_labels])
    
    return training_images, training_labels, test_images, test_labels

# Neural Network Class
class NeuralNetwork:
    def __init__(self, sizes):
        self.num_layers = len(sizes)
        self.sizes = sizes
        self.biases = [np.random.randn(y, 1) for y in sizes[1:]]
        self.weights = [np.random.randn(y, x) for x, y in zip(sizes[:-1], sizes[1:])]

    def feedforward(self, a):
        for b, w in zip(self.biases, self.weights):
            a = sigmoid(np.dot(w, a) + b)
        return a

    def update_mini_batch(self, mini_batch, eta):
        nabla_b = [np.zeros(b.shape) for b in self.biases]
        nabla_w = [np.zeros(w.shape) for w in self.weights]
        for x, y in mini_batch:
            delta_nabla_b, delta_nabla_w = self.backprop(x, y)
            nabla_b = [nb + dnb for nb, dnb in zip(nabla_b, delta_nabla_b)]
            nabla_w = [nw + dnw for nw, dnw in zip(nabla_w, delta_nabla_w)]
        self.weights = [w - (eta / len(mini_batch)) * nw for w, nw in zip(self.weights, nabla_w)]
        self.biases = [b - (eta / len(mini_batch)) * nb for b, nb in zip(self.biases, nabla_b)]

    def backprop(self, x, y):
        nabla_b = [np.zeros(b.shape) for b in self.biases]
        nabla_w = [np.zeros(w.shape) for w in self.weights]
        
        # Forward pass
        activation = x
        activations = [x]  # List to store all the activations, layer by layer
        zs = []  # List to store all the z vectors, layer by layer
        for b, w in zip(self.biases, self.weights):
            z = np.dot(w, activation) + b
            zs.append(z)
            activation = sigmoid(z)
            activations.append(activation)

        # Backward pass
        delta = self.cost_derivative(activations[-1], y) * sigmoid_prime(zs[-1])
        nabla_b[-1] = delta
        nabla_w[-1] = np.dot(delta, activations[-2].transpose())

        for l in range(2, self.num_layers):
            z = zs[-l]
            sp = sigmoid_prime(z)
            delta = np.dot(self.weights[-l+1].transpose(), delta) * sp
            nabla_b[-l] = delta
            nabla_w[-l] = np.dot(delta, activations[-l-1].transpose())
        return (nabla_b, nabla_w)

    def evaluate(self, test_data):
        test_results = [(np.argmax(self.feedforward(x)), y) for (x, y) in test_data]
        correct_predictions = sum(int(x == y) for (x, y) in test_results)
        accuracy = correct_predictions / len(test_data) * 100  # Calculate accuracy as a percentage
        return accuracy

    def cost_derivative(self, output_activations, y):
        return (output_activations - y)

# Sigmoid function
def sigmoid(z):
    return 1.0 / (1.0 + np.exp(-z))

# Derivative of sigmoid
def sigmoid_prime(z):
    return sigmoid(z) * (1 - sigmoid(z))

# Train the network
def train(network, training_data, epochs, mini_batch_size, eta, test_data=None):
    for epoch in range(epochs):
        np.random.shuffle(training_data)
        mini_batches = [training_data[k:k+mini_batch_size] for k in range(0, len(training_data), mini_batch_size)]

        for mini_batch in mini_batches:
            network.update_mini_batch(mini_batch, eta)

        if test_data:
            accuracy = network.evaluate(test_data)
            print(f"Epoch {epoch + 1}: Accuracy = {accuracy:.2f}%")  # Print accuracy in percentage

# Load and preprocess data
training_data, test_data = load_data_from_pkl('mnist.pkl')
training_images, training_labels, test_images, test_labels = preprocess_data(training_data, test_data)

# Combine images and labels into tuples
training_data = list(zip(training_images, training_labels))
test_data = list(zip(test_images, test_labels))

# Initialize and train the neural network
network = NeuralNetwork([784, 30, 10])  # Example: 784 input neurons, 30 hidden neurons, 10 output neurons
train(network, training_data, epochs=70, mini_batch_size=10, eta=1.5, test_data=test_data)
