import express from 'express';
import { Server, Socket as IOSocket } from 'socket.io';
import { Logger } from '@tehcn/log4js';
import { DefaultEventsMap } from 'socket.io/dist/typed-events';
import { CProgram } from './clink';

const app = express();
const server = app.listen(4269);
const io = new Server(server);
const logger = new Logger('PulseRendererEngine Server');

type Socket = IOSocket<DefaultEventsMap, DefaultEventsMap, DefaultEventsMap, any>;
type ConnectionMessage = { ip: string };

logger.log('server started on port 4269');

let clients: Socket[] = [];

const link = new CProgram()
    .addSourceFiles(
        'D:/dev/Pulse/PulseRendererEngine/src/c/main.cpp',
        'D:/dev/Pulse/PulseRendererEngine/src/c/vector3.cpp',
        'D:/dev/Pulse/PulseRendererEngine/src/c/string_utils.cpp',
        'D:/dev/Pulse/PulseRendererEngine/src/c/binary_tree.cpp',
    ).compile('D:/dev/Pulse/PulseRendererEngine/src/c/dist/main.exe').run();

process.openStdin();
logger.debug(link.proc.stdin.writable ? 'true' : 'false');
// process.stdin.pipe(link.proc.stdin);
link.proc.stdout.pipe(process.stdout);
link.proc.stderr.pipe(process.stderr);


process.stdin.on('data', (data) => {
    link.proc.stdin.write(data);
});

link.proc.stdin.on('close', () => {
    process.stdin.pause();
});

link.proc.stdin.on('data', data => {
    console.log(`Writing data to child process: ${data}`);
});

// link.proc.stdout.on('data', data => {
//     console.log(`Reading data from child process: ${data}`);
// });

link.proc.on('exit', (code, signal) => {
    logger.debug(`Child process exited with code ${code} and signal ${signal}`);
});

io.on('connection', (socket) => {
    logger.log(`client with id ${socket.id} is attempting to connect`);
    socket.on('c2s-data', (data) => {
        let raw = data.toString();
        switch (raw.split(';')[0]) {
            case 'conn':
                let data: ConnectionMessage = JSON.parse(raw.split(';')[1]);
                clients.push(socket);
                logger.log(`established connection with ${data.ip} (id: ${socket.id})`);
                break;
            default:
                logger.warn(`Received unhandled data: ${raw}`);
                break;
        }
    });

    socket.on('disconnect', (reason) => {
        logger.log(`client with id ${socket.id} disconnected: ${reason}`);
        clients = clients.filter(s => s.id != socket.id);
    });
});