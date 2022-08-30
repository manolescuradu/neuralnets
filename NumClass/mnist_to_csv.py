import torchvision
import torchvision.transforms as transforms

import random
import matplotlib.pyplot as plt

# download data
train_dataset = torchvision.datasets.MNIST(root='./data/', train=True, download=True, transform=transforms.ToTensor())
test_dataset = torchvision.datasets.MNIST(root='./data/', train=False, download=True, transform=transforms.ToTensor())

train_data = train_dataset.data
train_labels = train_dataset.targets

test_data = test_dataset.data
test_labels = test_dataset.targets

# print metadata & plot some image to make sure everything is correct
def verify(data, labels, i):
    print(f'images: {data.shape[0]} of size {data.shape[1]}x{data.shape[2]}')
    print(f'labels: {labels.shape[0]}')

    print(f'Image {i} is a {labels[i]}')

    plt.imshow(data[i], cmap='gray')
    plt.show()

# verify(train_data, train_labels, random.randint(0, train_data.shape[0]-1))
# verify(test_data,  test_labels,  random.randint(0, test_data.shape[0]-1))

# create CSVs (format: label,pixel1_1, pixel1_2, ... , pixel28_28)
def toCSV(file_name, data, labels):
    with open(file_name, "a") as f:
        for i, img in enumerate(data):
            f.write(str(train_labels[i].item()) + ',' +
                    ','.join([str(elem) for elem in img.reshape(-1).numpy()]) + '\n')

toCSV("data/mnist_train.csv", train_data, train_labels)
toCSV("data/mnist_test.csv", test_data, test_labels)
