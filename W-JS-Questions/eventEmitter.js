class MyEventEmitter {
    constructor() {
        this.__event_listeners = {};
    }


    on(event, listener) {
        if (!this.__event_listeners[event]) {
            this.__event_listeners[event] = [];
        }

        this.__event_listeners[event].push(listener);

        return true;
    }


    emit(event, ...args) {
        if (!this.__event_listeners[event]) {
            return false;
        }

        const listeners = this.__event_listeners[event];
        listeners.forEach(listener => {
            listener(...args)
        });
        return true;
    }

    off(event, listener) {
        if (!this.__event_listeners[event]) {
            return false;
        }

        const index = this.__event_listeners[event].indexOf(listener);

        this.__event_listeners[event].splice(index, 1);

        return true;
    }

    once(event, listener) {
        if (!this.__event_listeners[event]) return false;

        const wrapperFunction = (...args) => {
            listener(...args);
            this.off(event, wrapperFunction);
        }

        this.on(event, wrapperFunction);

        return true;
    }
}

const whatsappMessage = (username) => console.log("Sending Whatsapp Message! ", username)
const emailMessage = (username) => console.log("Sending Email! ", username)
const e = new MyEventEmitter();
e.on('user:signUp', (username) => console.log("User Sign Up! ", username))
e.on('user:signUp', emailMessage)
e.on('user:signUp', whatsappMessage)
e.on('user:logout', (username) => console.log("User Logout! ", username))

e.emit('user:signUp', "@wajahat_ahmed")
e.emit('user:logout', "@wajahat_ahmed")
e.emit('user:signUp', "@wajahat_ahmed2")
e.emit('user:logout', "@wajahat_ahmed2")

e.off('user:signUp', whatsappMessage)
e.off('user:signUp', emailMessage)
e.once('user:signUp', emailMessage)

e.emit('user:signUp', "@wajahat_ahmed3")
e.emit('user:logout', "@wajahat_ahmed3")

e.emit('user:signUp', "@wajahat_ahmed4")

