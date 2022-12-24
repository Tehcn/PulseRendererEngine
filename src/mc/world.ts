import { Chunk } from './chunk';

export class World {
    chunks: Chunk[];

    constructor() { this.chunks = []; }

    addChunk(chunk: Chunk): this {
        this.chunks.push(chunk);
        return this;
    }

    removeChunk(chunk: Chunk): this {
        this.chunks = this.chunks.filter(c => c != chunk);
        return this;
    }

    addChunks(chunks: Chunk[]): this {
        this.chunks.push(...chunks);
        return this;
    }

    removeChunks(chunks: Chunk[]): this {
        chunks.forEach(chunk => this.removeChunk(chunk));
        return this;
    }
}