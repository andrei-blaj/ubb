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

const songTitles = ['Seconds For You', 'Melody Of Stars', 'Dream Of My Door', 'Diamond Promises', 'Wouldn\'t It Be Nice'];
const songDescription = ['Very good!', 'Slightly used', 'Top condition', 'Somehow new!'];
const songAlbums = ['One', 'Two', 'Four', 'Nine'];
const songGenre = ['Blues', 'Country', 'Electronic', 'Hip Hop', 'Jazz', 'Latin', 'Pop', 'R&B', 'Rock', 'Ska'];
const songs = [];
for (let i = 0; i < 50; i++) {
    songs.push({
        id: i + 1,
        title: songTitles[getRandomInt(0, songTitles.length)],
        description: songDescription[getRandomInt(0, songDescription.length)],
        album: songAlbums[getRandomInt(0, songAlbums.length)],
        genre: songGenre[getRandomInt(0, songGenre.length)],
        year: getRandomInt(1950, 2019)
    });
}

const router = new Router();
router.get('/genres', ctx => {
    ctx.response.body = songGenre;
    ctx.response.status = 200;
});

router.get('/all', ctx => {
    ctx.response.body = songs;
    ctx.response.status = 200;
});


router.get('/songs/:genre', ctx => {
    // console.log("ctx: " + JSON.stringify(ctx));
    const headers = ctx.params;
    const genre = headers.genre;
    // console.log("genre: " + JSON.stringify(genre));
    ctx.response.body = songs.filter(song => song.genre == genre);
    // console.log("body: " + JSON.stringify(ctx.response.body));
    ctx.response.status = 200;
});


router.post('/song', ctx => {
    // console.log("ctx: " + JSON.stringify(ctx));
    const headers = ctx.request.body;
    // console.log("body: " + JSON.stringify(headers));
    const title = headers.title;
    const description = headers.description;
    const album = headers.album;
    const genre = headers.genre;
    const year = headers.year;
    if (typeof title !== 'undefined' && typeof description !== 'undefined' && typeof album !== 'undefined'
        && typeof genre !== 'undefined' && typeof year !== 'undefined') {
        const index = songs.findIndex(song => song.title == title &&
            song.album == album && song.genre == genre);
        if (index !== -1) {
            console.log("Song already exists!");
            ctx.response.body = {text: 'Song already exists!'};
            ctx.response.status = 404;
        } else {
            let maxId = Math.max.apply(Math, songs.map(function (song) {
                return song.id;
            })) + 1;
            let song = {
                id: maxId,
                title,
                description,
                album,
                genre,
                year
            };
            songs.push(song);
            ctx.response.body = song;
            ctx.response.status = 200;
        }
    } else {
        console.log("Missing or invalid: title, description, album, genre or year!");
        ctx.response.body = {text: 'Missing or invalid: title, description, album, genre or year!'};
        ctx.response.status = 404;
    }
});

router.del('/song/:id', ctx => {
    // console.log("ctx: " + JSON.stringify(ctx));
    const headers = ctx.params;
    // console.log("body: " + JSON.stringify(headers));
    const id = headers.id;
    if (typeof id !== 'undefined') {
        const index = songs.findIndex(song => song.id == id);
        if (index === -1) {
            console.log("No song with id: " + id);
            ctx.response.body = {text: 'Invalid song id'};
            ctx.response.status = 404;
        } else {
            let song = songs[index];
            songs.splice(index, 1);
            ctx.response.body = song;
            ctx.response.status = 200;
        }
    } else {
        ctx.response.body = {text: 'Id missing or invalid'};
        ctx.response.status = 404;
    }
});

app.use(router.routes());
app.use(router.allowedMethods());

server.listen(2224);
