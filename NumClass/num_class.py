import torch
import torch.nn as nn
import torchvision
import torchvision.transforms as transforms
import matplotlib.pyplot as plt

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

# hypermarams

# structure
input_size = 784
hidden_size = 100
output_size = 10

# training
num_epochs = 5
batch_size = 4
learning_rate = 0.001

# (down)load & prepare dataset

train_dataset = torchvision.datasets.MNIST(root='./data/', train=True, download=True, transform=transforms.ToTensor())
test_dataset = torchvision.datasets.MNIST(root='./data/', train=False, download=True, transform=transforms.ToTensor())

train_loader = torch.utils.data.DataLoader(dataset=train_dataset, batch_size=batch_size, shuffle=True)
test_loader = torch.utils.data.DataLoader(dataset=test_dataset, batch_size=batch_size, shuffle=False)

class NeuralNet(nn.Module):

    def __init__(self, input_size, hidden_size, output_size):
        super().__init__()
        self.l1 = nn.Linear(input_size, hidden_size)
        self.activ = nn.ReLU()
        self.l2 = nn.Linear(hidden_size, output_size)

    def forward(self, sample):
        out = self.l1(sample)
        out = self.activ(out)
        out = self.l2(out)
        return out

model = NeuralNet(input_size, hidden_size, output_size)
model.to(device)

loss_fn = nn.CrossEntropyLoss()
optimizer = torch.optim.Adam(model.parameters(), lr=learning_rate)

# training
for epoch in range(num_epochs):
    for i, (images, labels) in enumerate(train_loader):
        images = images.reshape(-1, 28*28).to(device)

        norm_labels = torch.zeros(labels.shape[0], 10, dtype = torch.float32)
        for i, l in enumerate(labels):
            norm_labels[i][l] = 1;
        norm_labels = norm_labels.to(device)

        pred_labels = model(images)

        loss = loss_fn(pred_labels, norm_labels)

        optimizer.zero_grad()
        loss.backward()
        optimizer.step()

    print(f'epoch {epoch+1} / {num_epochs}')

# verification
with torch.no_grad():
    total=0
    correct=0

    for i, (images, labels) in enumerate(test_loader):
        #cimages = images.numpy()
        images = images.reshape(-1, 28*28).to(device)
        labels = labels.to(device)

        pred_labels = model(images).argmax(1)

        total += labels.shape[0]
        correct += (pred_labels == labels).sum().item()

        """        
        for i, pred in enumerate(pred_labels):
            if pred != labels[i]:
                print(f'predicted {pred}, expected {labels[i]}')
                plt.imshow(cimages[i][0], cmap='gray')
                plt.show()
        """
     
    print(f'accuracy: {100.0*correct/total:.2f}% - {correct} out of {total}')
