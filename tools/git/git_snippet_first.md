#### 1.reset file
```Bash
pwd
##cd 到要reset file的路径下
git reset 'hash-code' ./filename
git checkout -- ./filename
```
#### 2.git checkout error
```
Unlink of file '......' failed. Should I try again?
```
出现这种情况，基本上可以说是文件被占用了，git的LFS是无法


#### 3.reset folader
```Bash
pwd
##cd 到要reset folder的parent路径
git reset 'hash-code' ./folder
git checkout -- ./folder
```
如果出现"fatal: Cannot do hard reset with paths."的错误，没有指定路径，或者路径指定错误
#### 4.push 单个文件或者文件夹
```Bash
pwd
##cd 到包含这些文件的总文件夹，但是之后参数要带上相对路径
git add foladers/filenames
git commit -m "msg" foladers/filenames
git push origin master
```

#### 5.删除某个commit
找到一个[参考](https://www.clock.co.uk/insight/deleting-a-git-commit)，觉得靠谱，之后试一试
>Using Cherry Pick
>Step 1: Find the commit before the commit you want to remove git log
>
>Step 2: Checkout that commit git checkout <commit hash>
>
>Step 3: Make a new branch using your current checkout commit git checkout -b <new >branch>
>
>Step 4: Now you need to add the commit after the removed commit git cherry-pick ><commit hash>
>
>Step 5: Now repeat Step 4 for all other commits you want to keep.
>
>Step 6: Once all commits have been added to your new branch and have been commited. >Check that everything is in the correct state and working as intended. Double check >everything has been commited: git status
>
>Step 7: Switch to your broken branch git checkout <broken branch>
>
>Step 8: Now perform a hard reset on the broken branch to the commit prior to the one >your want to remove git reset --hard <commit hash>
>
>Step 9: Merge your fixed branch into this branch git merge <branch name>
>
>Step 10: Push the merged changes back to origin. WARNING: This will overwrite the >remote repo! git push --force origin <branch name>
>
>You can do the process without creating a new branch by replacing Step 2 & 3 with >Step 8 then not carry out Step 7 & 9.

#### 6.UE4 & git
>这里简单介绍下以Git LFS作为版本管理的工作流程。UE4的项目资源大体可以分为二进制格式和文本格式的资源。这里的分类依据，主要是基于是否可以合并。所有UE4的.uasset和.umap等二进制资源，由于无法简单的合并，所以不能多人同时修改；而代码和其他文本类资源，因为可以支持合并，所以可以支持多人同时修改。这类无法多人修改的二进制资源，在其他版本管理软件中会以文件锁的方式来操作，也就是资源修改需要先Checkout，修改完需要Checkin。作为Git扩展的LFS除了提供大文件储存功能外，还提供了类似的文件锁功能，可以满足Checkout的这种工作方式。
>一般来说，如果你想要修改关卡等二进制资源，需要先运行Get Latest，从服务器上同步最新的资源到本地。接下来就是修改，你可以在UE4里直接修改，UE4会自动执行对应文件的Checkout操作；或者你可以先主动的Checkout需要修改的文件，然后修改。主动Checkout可以确保其他用户在此时没有修改这些文件，而且在Checkout成功后，可以禁止其他用户接下来的修改请求。当资源修改完成后，需要尽快的提交，以释放相应的文件锁。UE4提交文件的时候会自动Revert没有修改到的文件，但是推荐在Git Tool里先执行Revert Unchanged操作，这样可以从Change List里看见那些文件实际做了修改。如果不小心改动到了不需要的文件，可以选中这些文件，然后Revert掉修改。检查完成后就可以提交到服务器了。
>代码等文本文件，由于不涉及到Checkout，所以可以基于Git原生的工作流，这里就不再叙述了。

#### 7.grep
```
git grep -R 'xxx' ./app/
//搜索在app目录下的所有xxx字符串
```


#### 8.pull 指定某一个文件或文件夹
默认情况下，git pull 操作会把远程仓库的所有最新数据更新到本地。
但是，如果你只想更新指定的某一个文件或文件夹，该怎么操作呢？
设置 core.sparsecheckout为 true
```
  $ git config core.sparsecheckout true
```
core.sparsecheckout用于控制是否允许设置pull指定文件/夹，true为允许。
此方法适用于 Git1.7.0 以后版本，之前的版本没有这个功能。
在.git/info/sparse-checkout文件中（如果没有则创建）添加指定的文件/夹
最后，拉取想要的分支即可实现checkout指定文件/夹。
```
  $ git pull origin master
```

#### 9.路径问题
项目内，直接用 "/" 来定义 ".git"的父目录，也就是项目目录。


#### 