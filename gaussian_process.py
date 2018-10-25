#!/usr/bin/env python

from __future__ import division
import numpy as np
import matplotlib.pyplot as pl
import scipy.io
from PIL import Image
from PIL import ImageOps 


""" This is code for simple GP regression. It assumes a zero mean GP Prior """

global X, y, N, lS, sigmaSqF, sigmaSqN, K 

# This is the true unknown function we are trying to approximate
#f = lambda x: np.sin(0.9*x).flatten()
#print f
#f = lambda x: (0.25*(x**2)).flatten()

def f():  #returns the value of the marginal loglikelihood
    global X, y, N, lS, sigmaSqF, sigmaSqN, K
    
    """
    #kP = lS**2
    kernel = np.zeros((N,N))
    for j in range(N):
        for k in range(N):
            sqdist = np.linalg.norm(X[j] - X[k])
            kernel[j][k] = sigmaSqF*np.exp(-.5 * (1/lS) * sqdist)
            #print 'ker', kernel[j][k]
    """    
    #K = kernel
    Kinv = np.linalg.inv(K + sigmaSqN*np.eye(N))
    loglik = -0.5*np.dot(y.T,np.dot(Kinv,y)) - 0.5*np.log(np.linalg.det(K)) - 0.5*N*np.log(2*np.pi)
    #print 'loglik', loglik
    return loglik
    

# Define the kernel
def kernel(a, b, e, f):
    """ GP squared exponential kernel """
    global X, y, N, ls, sigmaSqF, sigmaSqN
    #kP = lS**2

    kernel = np.zeros((e,f))
    for j in range(e):
        for k in range(f):
            sqdist = np.linalg.norm(a[j] - b[k])
            kernel[j][k] = sigmaSqF*np.exp(-.5 * (1/lS) * sqdist)
          
    return kernel

lS = np.exp(0.1992)#5                 # lengthscale squared  #0.1, 1, 2, 5, 10
sigmaSqF = np.exp(4.3452)               #signal variance
sigmaSqN = 0.2310      #noise variance
N = 500                 # number of training points.
n = 300

# Sample some input points and noisy versions of the function evaluated at
# these points. 


# Load training set
train = scipy.io.loadmat("sarcos_inv.mat")
# Inputs  (1st joint positions, 1st joint velocities, 1st joint accelerations)
X = np.array(train["sarcos_inv"][:N, :14])


#Output(Torque) of training set for 1st joint
y = np.array(train["sarcos_inv"][:N, 27])



#compute covariance matrix for the training set
K = kernel(X, X, N, N)
#print 'KKKKK', K


#compute logliklihoodij
#print 'loglik = ',f()





#compute the cholesky decomposition for K
L = np.linalg.cholesky(K + sigmaSqN*np.eye(N))


# points we're going to make predictions at.
# Load test set
test = scipy.io.loadmat("sarcos_inv_test.mat")
Xtest = test["sarcos_inv_test"][:n, :14]
Ytest = test["sarcos_inv_test"][:n, 27]
print Ytest


# compute the mean at our test points.

#computes the covariance matrix between the training points and test points
kTest = kernel(X, Xtest, N, n) 
#print kTest
print "" 
print 'heyyyy'

"""
ttt = 'LS = {} , sigmaSqF = {}, train = {}, test = {}'.format(lS, sigmaSqF, N, n)
title = ttt + '.'
titl = 'matrix2/'+ title
K_ = kTest
K_ = K_/np.amax(K_)
K_ = 1*np.ones((N, n)) - K_
#K = 254.5*np.ones((N,N))

print K_
im = pl.imshow(K_, cmap='gray', interpolation = 'none')
pl.savefig(titl, bbox_inches='tight')
pl.show()
"""

Lk = np.linalg.solve(L,kTest)
Nk = np.linalg.solve(L, y)
#print kTest

# compute the mean (mu) at the test points 
mu = np.dot(Lk.T, Nk)
print 'muuuu', mu.shape

pred = scipy.io.loadmat("gpVariables_nonddq.mat")['muTest']
mat_pred = np.array(pred[:n])
#mat_pred = np.reshape(mat_pred, (n, 1))
mat_pred = mat_pred.flatten()
print 'mat_pred ',mat_pred.shape



# compute the variance at our test points.
K_ = kernel(Xtest, Xtest, n, n)
#print 'k_k_kkkk', K_


sigma2 = np.diag(K_) - np.sum(Lk**2, axis=0)
#print 'LK22 shape',np.sum(Lk**2, axis=0)
sigma = np.sqrt(sigma2)
#print 'sigma',s


VAR = np.var(Ytest)     #computes the variance of the target values
sumTot = 0
sumTot2 = 0

for j in range(len(mu)):        
    print [mu[j], Ytest[j], mat_pred[j]]
    SE = (mu[j] - Ytest[j])**2
    SE2 = (mat_pred[j] - Ytest[j])**2
    sumTot += SE                    #computes the sum of squared squared error 
    sumTot2 += SE2
MSE = sumTot/len(mu)                #computes the mean squared error
nMSE = MSE/VAR                      #computes the normalized mean square error
print "nMSE = ",nMSE

MSE2 = sumTot2/len(mat_pred)                #computes the mean squared error
nMSE2 = MSE2/VAR                      #computes the normalized mean square error
print "nMSE2 = ",nMSE2



xtrain = np.array(np.arange(1, N+1))#np.array(train["sarcos_inv"][:N, 0])
xtest = np.array(np.arange(1,n+1))#np.array(test["sparseGpVariables"][:n, 0])
ymin = min(Ytest)
ymax = max(Ytest)

#ttt = 'LS = {} , sigmaSqF = {}, sigmaSqN = {}, train = {}, test = {}'.format(lS, sigmaSqF, sigmaSqN, N, n)
ttt = 'Joint 111 toolbox , LS = {}'.format(lS)
title = ttt + '.'
titleS = 'joints/jointA/'+ title
#print title


# PLOTS:
pl.figure(1)
pl.clf()
#pl.plot(xtrain, y, 'g+', ms=10)
pl.plot(xtest, Ytest, 'r-', ms = 10)#, label="Test values")
pl.gca().fill_between(xtest.flat, mu-3*sigma, mu+3*sigma, color="#dddddd")
#pl.plot(xtest, mu, 'b-', ms = 10)#, label="Predicted values")
pl.plot(xtest, mat_pred, 'g-', ms = 10)#, label="Predicted values")
pl.title(title)
#pl.gca().legend(('Test values','Predicted values', 'mat_pred'), loc=0, labelspacing=0.5)
#pl.gca().legend(('Test values','Predicted values'), loc=0, labelspacing=0.5)
pl.gca().legend(('Test values', 'Toolbox_pred'), loc=0, labelspacing=0.5)
pl.savefig(titleS, bbox_inches='tight')
# pl.axis([0,n,ymin,ymax])
pl.show()


"""
# draw samples from the prior at our test points.
L = np.linalg.cholesky(K_ + 1e-6*np.eye(n))
f_prior = np.dot(L, np.random.normal(size=(n,10)))
pl.figure(2)
pl.clf()
pl.plot(Xtest, f_prior)
pl.title('Ten samples from the GP prior')
pl.axis([-5, 5, -3, 3])
pl.savefig('prior.png', bbox_inches='tight')

# draw samples from the posterior at our test points.
L = np.linalg.cholesky(K_ + 1e-6*np.eye(n) - np.dot(Lk.T, Lk))
f_post = mu.reshape(-1,1) + np.dot(L, np.random.normal(size=(n,10)))
pl.figure(3)
pl.clf()
pl.plot(Xtest, f_post)
pl.title('Ten samples from the GP posterior')
pl.axis([-5, 5, -3, 3])
pl.savefig('post.png', bbox_inches='tight')

"""
#pl.show()
