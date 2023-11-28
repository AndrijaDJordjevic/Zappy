##
## EPITECH PROJECT, 2023
## neural
## File description:
## neural
##

import numpy as np

class NeuralNetwork:
    def __init__(self, current_statuts):
        self.input_size = 2
        self.output_size = 1
        self.hidden_size = 3
        self.weights_input_hidden = np.random.randn(self.input_size, self.hidden_size)
        self.weights_hidden_output = np.random.randn(self.hidden_size, self.output_size)
        self.input_trainning_data = np.array(([90, 0], [91, 122], [93, 22], [95, 0], [100, 0], [95, 89], [97, 22], [115, 0], current_statuts), dtype=float)
        self.output_training_data = np.array(([0], [0], [0], [0], [1], [1], [1], [1]), dtype=float)

    def forward_propagation(self, X):
        self.hidden_layer_input = np.dot(X, self.weights_input_hidden)
        self.hidden_layer_output = self.sigmoid(self.hidden_layer_input)
        self.output_layer_input = np.dot(self.hidden_layer_output, self.weights_hidden_output)
        self.output = self.sigmoid(self.output_layer_input)
        return self.output

    def sigmoid(self, x):
        return 1 / (1 + np.exp(-x))

    def sigmoid_derivative(self, x):
        return x * (1 - x)

    def backward_propagation(self, X, y, output):
        self.output_error = y - output
        self.output_delta = self.output_error * self.sigmoid_derivative(output)
        self.hidden_error = self.output_delta.dot(self.weights_hidden_output.T)
        self.hidden_delta = self.hidden_error * self.sigmoid_derivative(self.hidden_layer_output)
        self.weights_input_hidden += X.T.dot(self.hidden_delta)
        self.weights_hidden_output += self.hidden_layer_output.T.dot(self.output_delta)

    def train(self, X, y, iterations):
        for i in range(iterations):
            output = self.forward_propagation(X)
            self.backward_propagation(X, y, output)

    def predict(self, X_prediction):
        output = self.forward_propagation(X_prediction)
        if output <= 0.5:
            print("Need to eat!")
            return (1)
        else:
            print("Don't need to eat!")
            return (0)

    def run_neural_network(self):
        self.input_trainning_data = self.input_trainning_data / np.amax(self.input_trainning_data, axis=0)
        X_train = self.input_trainning_data[:8]
        X_prediction = self.input_trainning_data[8:]
        self.train(X_train, self.output_training_data, iterations=3000)
        return self.predict(X_prediction)

def foodPercentage(total_cases, food_cases):
    percentage = (food_cases / total_cases) * 100
    return percentage

# cell = 9
# food_map = 4
# food_on = 5
# food_per = round(foodPercentage(cell, food_map), 0)
# neural_network = NeuralNetwork([food_on, food_per])
# pipi = neural_network.run_neural_network()

# if (pipi == 0):
#     print("Hello world")