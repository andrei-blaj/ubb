const koa = require('koa');
const app = new koa();
const server = require('http').createServer(app.callback());
const WebSocket = require('ws');
const wss = new WebSocket.Server({server});
const Router = require('koa-router');
const cors = require('koa-cors');
const bodyParser = require('koa-bodyparser');
const convert = require('koa-convert');

app.use(bodyParser());
app.use(convert(cors()));
app.use(async (ctx, next) => {
    const start = new Date();
    await next();
    const ms = new Date() - start;
    console.log(`${ctx.method} ${ctx.url} ${ctx.response.status} - ${ms}ms`);
});

const getRandomInt = (min, max) => {
    min = Math.ceil(min);
    max = Math.floor(max);
    return Math.floor(Math.random() * (max - min)) + min;
};

const productNames = ['Book', 'Phone', 'Tablet', 'Laptop', 'Computer'];
const productDescription = ['Very good!', 'Slightly used', 'Top condition', 'Somehow new!'];
const statusTypes = ['new', 'sold', 'popular', 'old', 'discounted'];
const products = [];
for (let i = 0; i < 10; i++) {
    products.push({
        id: i + 1,
        name: productNames[getRandomInt(0, productNames.length)],
        description: productDescription[getRandomInt(0, productDescription.length)],
        quantity: getRandomInt(1, 100),
        price: getRandomInt(1, 10000),
        status: statusTypes[getRandomInt(0, statusTypes.length)]
    });
}

const router = new Router();
router.get('/products', ctx => {
    ctx.response.body = products.filter(product => product.status !== statusTypes[1]);
    ctx.response.status = 200;
});

router.get('/all', ctx => {
    ctx.response.body = products;
    ctx.response.status = 200;
});

router.post('/buyProduct', ctx => {
    // console.log("ctx: " + JSON.stringify(ctx));
    const headers = ctx.request.body;
    // console.log("body: " + JSON.stringify(headers));
    const id = headers.id;
    const quantity = headers.quantity;
    if (typeof id !== 'undefined' && typeof quantity !== 'undefined') {
        const index = products.findIndex(product => product.id == id && product.quantity >= quantity);
        if (index === -1) {
            console.log("Product not available!");
            ctx.response.body = {text: 'Product not available!'};
            ctx.response.status = 404;
        } else {
            let product = products[index];
            product.quantity -= 1;
            if (product.quantity === 0) {
                product.status = statusTypes[1]
            }
            ctx.response.body = product;
            ctx.response.status = 200;
        }
    } else {
        console.log("Missing or invalid: id or quantity!");
        ctx.response.body = {text: 'Missing or invalid: id or quantity!'};
        ctx.response.status = 404;
    }
});

const broadcast = (data) =>
    wss.clients.forEach((client) => {
        if (client.readyState === WebSocket.OPEN) {
            client.send(JSON.stringify(data));
        }
    });

router.post('/product', ctx => {
    // console.log("ctx: " + JSON.stringify(ctx));
    const headers = ctx.request.body;
    // console.log("body: " + JSON.stringify(headers));
    const name = headers.name;
    const description = headers.description;
    const quantity = headers.quantity;
    const price = headers.price;
    if (typeof name !== 'undefined' && typeof description !== 'undefined' && typeof quantity !== 'undefined'
        && typeof price !== 'undefined') {
        const index = products.findIndex(product => product.name == name &&
            product.description == description);
        if (index !== -1) {
            console.log("Product already exists!");
            ctx.response.body = {text: 'Product already exists!'};
            ctx.response.status = 404;
        } else {
            let maxId = Math.max.apply(Math, products.map(function (product) {
                return product.id;
            })) + 1;
            let product = {
                id: maxId,
                name,
                description,
                quantity,
                price,
                status: statusTypes[0]
            };
            products.push(product);
            broadcast(product);
            ctx.response.body = product;
            ctx.response.status = 200;
        }
    } else {
        console.log("Missing or invalid: name, description, quantity or price!");
        ctx.response.body = {text: 'Missing or invalid: name, description, quantity or price!"'};
        ctx.response.status = 404;
    }
});

router.del('/product/:id', ctx => {
    console.log("ctx: " + JSON.stringify(ctx));
    const headers = ctx.params;
    console.log("body: " + JSON.stringify(headers));
    const id = headers.id;
    if (typeof id !== 'undefined') {
        const index = products.findIndex(product => product.id == id);
        if (index === -1) {
            console.log("No product with id: " + id);
            ctx.response.body = {text: 'Invalid product id'};
            ctx.response.status = 404;
        } else {
            let product = products[index];
            products.splice(index, 1);
            ctx.response.body = product;
            ctx.response.status = 200;
        }
    } else {
        ctx.response.body = {text: 'Id missing or invalid'};
        ctx.response.status = 404;
    }
});

app.use(router.routes());
app.use(router.allowedMethods());

server.listen(2024);
