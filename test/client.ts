import { io } from 'socket.io-client';
import { Logger } from '@tehcn/log4js';

const logger = new Logger('TestClient');
const socket = io('ws://localhost:4269');

socket.connect();

socket.on('connect', () => {
    socket.emit('c2s-data', 'conn;{"ip": "127.0.0.1"}');
    logger.log('connnected!');
});