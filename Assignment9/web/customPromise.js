function NewPromise(executorFunction) {
  this.state = "pending";
  this.result = undefined;

  let successCallBack = null;
  let errorCallBack = null;

  const resolve = (value) => {
    this.state = "fulfilled";
    this.result = value;

    if (successCallBack) {
      successCallBack(value);
    }
  };

  const reject = (error) => {
    this.state = "rejected";
    this.result = error;

    if (errorCallBack) {
      errorCallBack(error);
    }
  };

  this.then = function (successCallBackFn) {
    return new NewPromise((resolveNext, rejectNext) => {
      successCallBack = (value) => {
        const result = successCallBackFn(value);

        resolveNext(result);
      };
    });
  };

  this.catch = function (errorCallBackFn) {
    errorCallBack = (error) => {
      errorCallBackFn(error);
    };

    return this;
  };

  executorFunction(resolve, reject);
}


new NewPromise((resolve) => { resolve(5); })
  .then((value) => { return value * 2; })
  .then((value) => { return value * 5; })
  .then((value) => { console.log(value); });

